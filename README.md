 🚁 Energy-Efficient Drone Delivery Optimization

📌 Overview
This project focuses on optimizing drone delivery routes to minimize total energy consumption instead of just distance.

It models real-world delivery scenarios where drones must deliver packages across multiple locations while considering:
- Distance between locations
- Payload weight
- Battery constraints

The core problem is based on the Travelling Salesman Problem (TSP), enhanced with an energy-based cost model.

 💡 Problem Statement
Traditional route optimization focuses on finding the shortest path. However, in drone delivery systems:

Energy consumption is not equal to distance.

Factors like payload weight and environmental conditions affect energy usage.

This project aims to:
- Find the most energy-efficient route
- Compare multiple algorithms
- Simulate real-world delivery constraints

⚙️ Features

 🧠 Multiple Optimization Algorithms
- Greedy Approach → Fast but not optimal
- Exact TSP (Brute Force / DP) → Optimal but expensive
- Approximation Algorithm → Balanced performance

 🔋 Energy Model (Key Highlight)
Energy is calculated using:
Energy = Base + (Distance × Factor × (1 + Payload Weight))

 📊 Route Comparison
- Compare different algorithms
- Analyze efficiency vs computation time

 🏗️ Project Structure

daa/
│── src/
│   └── backend/
│       ├── graph.c / graph.h
│       ├── energy_model.c / energy_model.h
│       ├── tsp_greedy.c / tsp_greedy.h
│       ├── tsp_exact.c / tsp_exact.h
│       ├── tsp_approx.c / tsp_approx.h
│       ├── main.c
│
│── bin/
│   └── optimizer.exe
│
│── build.bat
│── node_modules/

🚀 How to Run

### Option 1: Run Executable
cd bin
optimizer.exe

### Option 2: Build from Source
cd daa
build.bat

### Optional: Node Integration
npm install
npm start

 📈 Future Enhancements
- Genetic Algorithm for better optimization
- 2-Opt / 3-Opt route improvements
- Weather-based energy adjustments
- Smart battery constraint handling
- Real-world map integration


 🎯 Key Learnings
- Applied DSA concepts to real-world problems
- Understood trade-offs between accuracy vs performance
- Built a hybrid system combining C + Node.js
- Modeled realistic energy-based cost functions

 🧑‍💻 Tech Stack
- C (Core algorithm)
- Node.js (Backend integration)
- Data Structures & Algorithms

⭐ Why This Project Stands Out
- Goes beyond basic TSP
- Includes real-world constraints (energy, payload)
- Compares multiple algorithms
- Strong system design + DSA combination

 📌 Author
Rishika Shrivastava

📜 License
This project is for educational and research purposes.

🔥 Quote
Not all shortest paths are energy-efficient — this project proves it.
