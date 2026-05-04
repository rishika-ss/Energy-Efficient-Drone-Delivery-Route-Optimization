const express = require('express');
const cors = require('cors');
const { spawn } = require('child_process');
const path = require('path');

const app = express();
const PORT = 3000;

app.use(cors());
app.use(express.json());
app.use(express.static('public'));

app.post('/api/plan-route', (req, res) => {
    const { algorithm, payload_weight, nodes } = req.body;

    if (!nodes || nodes.length < 2) {
        return res.status(400).json({ error: "Need at least 2 nodes" });
    }

    let inputStr = `${algorithm}\n${payload_weight}\n${nodes.length}\n`;
    nodes.forEach(n => {
        inputStr += `${n.x} ${n.y}\n`;
    });

    const exePath = path.join(__dirname, 'bin', 'optimizer.exe');
    
    const child = spawn(exePath);

    let outputData = '';
    let errorData = '';

    child.stdout.on('data', (data) => {
        outputData += data.toString();
    });

    child.stderr.on('data', (data) => {
        errorData += data.toString();
    });

    child.on('close', (code) => {
        if (code !== 0) {
            console.error("Executable error:", errorData);
            return res.status(500).json({ error: "Backend execution failed" });
        }
        
        try {
            const result = JSON.parse(outputData);
            res.json(result);
        } catch (e) {
            console.error("Failed to parse output:", outputData);
            res.status(500).json({ error: "Invalid output from backend" });
        }
    });

    child.on('error', (err) => {
        console.error("Spawn error:", err);
        res.status(500).json({ error: "Failed to start backend executable" });
    });

    child.stdin.write(inputStr);
    child.stdin.end();
});

app.listen(PORT, () => {
    console.log(`Server running at http://localhost:${PORT}`);
});
