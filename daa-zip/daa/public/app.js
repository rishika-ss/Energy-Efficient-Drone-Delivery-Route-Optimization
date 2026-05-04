const canvas = document.getElementById('mapCanvas');
const ctx = canvas.getContext('2d');
let nodes = [];
let route = [];

const algoSelect = document.getElementById('algorithm');
const payloadInput = document.getElementById('payload');
const numNodesInput = document.getElementById('num-nodes');
const btnGenerate = document.getElementById('btn-generate');
const btnClear = document.getElementById('btn-clear');
const btnOptimize = document.getElementById('btn-optimize');
const btnCompareAll = document.getElementById('btn-compare-all');
const resultsBody = document.getElementById('results-body');

const CW = canvas.width;
const CH = canvas.height;

function drawMap() {
    ctx.clearRect(0, 0, CW, CH);
    
    if (route.length > 0 && nodes.length > 0) {
        ctx.beginPath();
        ctx.strokeStyle = 'rgba(56, 189, 248, 0.6)';
        ctx.lineWidth = 3;
        
        ctx.moveTo(nodes[route[0]].x, nodes[route[0]].y);
        for (let i = 1; i < route.length; i++) {
            ctx.lineTo(nodes[route[i]].x, nodes[route[i]].y);
        }
        ctx.lineTo(nodes[route[0]].x, nodes[route[0]].y);
        ctx.stroke();
    }

    nodes.forEach((node, index) => {
        ctx.beginPath();
        ctx.fillStyle = index === 0 ? '#ef4444' : '#f59e0b';
        ctx.arc(node.x, node.y, index === 0 ? 8 : 6, 0, Math.PI * 2);
        ctx.fill();
        ctx.strokeStyle = '#fff';
        ctx.lineWidth = 1.5;
        ctx.stroke();

        ctx.fillStyle = '#fff';
        ctx.font = '10px Inter';
        ctx.fillText(index, node.x + 10, node.y - 10);
    });
}

canvas.addEventListener('click', (e) => {
    const rect = canvas.getBoundingClientRect();
    const scaleX = canvas.width / rect.width;
    const scaleY = canvas.height / rect.height;

    const x = (e.clientX - rect.left) * scaleX;
    const y = (e.clientY - rect.top) * scaleY;
    
    nodes.push({ x, y });
    route = [];
    drawMap();
});

btnGenerate.addEventListener('click', () => {
    const count = parseInt(numNodesInput.value) || 10;
    nodes = [];
    route = [];
    for (let i = 0; i < count; i++) {
        nodes.push({
            x: Math.random() * (CW - 40) + 20,
            y: Math.random() * (CH - 40) + 20
        });
    }
    drawMap();
});

btnClear.addEventListener('click', () => {
    nodes = [];
    route = [];
    resultsBody.innerHTML = '';
    drawMap();
});

async function runOptimization(algorithm) {
    if (nodes.length < 2) {
        alert("Please add at least 2 nodes");
        return null;
    }
    if (algorithm === 'exact' && nodes.length > 12) {
        alert("Exact algorithm is too slow for more than 12 nodes. Try Greedy or Approx.");
        return null;
    }

    const payload = parseFloat(payloadInput.value) || 0;

    btnOptimize.disabled = true;
    btnOptimize.textContent = 'Optimizing...';

    try {
        const response = await fetch('/api/plan-route', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({
                algorithm: algorithm,
                payload_weight: payload,
                nodes: nodes
            })
        });

        const data = await response.json();
        
        if (data.error) {
            alert("Error: " + data.error);
            return null;
        }

        return data;
    } catch (error) {
        console.error(error);
        alert("Failed to connect to backend");
        return null;
    } finally {
        btnOptimize.disabled = false;
        btnOptimize.textContent = 'Optimize Route';
    }
}

function updateTable(data, append = false) {
    if (!data) return;
    
    const row = `
        <tr>
            <td><strong>${data.algorithm.toUpperCase()}</strong></td>
            <td>${data.distance.toFixed(2)} units</td>
            <td>${data.energy.toFixed(2)} units</td>
            <td>${data.time_ms.toFixed(4)} ms</td>
        </tr>
    `;

    if (append) {
        resultsBody.insertAdjacentHTML('beforeend', row);
    } else {
        resultsBody.innerHTML = row;
    }
}

btnOptimize.addEventListener('click', async () => {
    const algo = algoSelect.value;
    const data = await runOptimization(algo);
    if (data) {
        route = data.path;
        drawMap();
        updateTable(data, false);
    }
});

btnCompareAll.addEventListener('click', async () => {
    if (nodes.length < 2) return;
    resultsBody.innerHTML = '';
    
    const algos = ['greedy', 'approx'];
    if (nodes.length <= 12) {
        algos.push('exact');
    } else {
        resultsBody.innerHTML = '<tr><td colspan="4" style="color:var(--danger-color)">Exact algorithm skipped (too many nodes)</td></tr>';
    }

    let bestRoute = null;
    let minEnergy = Infinity;

    for (const algo of algos) {
        const data = await runOptimization(algo);
        if (data) {
            updateTable(data, true);
            if (data.energy < minEnergy) {
                minEnergy = data.energy;
                bestRoute = data.path;
            }
        }
    }

    if (bestRoute) {
        route = bestRoute;
        drawMap();
    }
});

drawMap();
