# 🚁 Energy-Efficient Drone Delivery Optimization

An algorithmic route optimization system designed to minimize **drone energy consumption**, not just travel distance.

This project extends the classical **Travelling Salesman Problem (TSP)** by introducing an energy-aware cost model that considers factors such as:

- 📍 Distance between delivery locations
- 📦 Payload weight
- 🔋 Battery limitations
- ⚡ Energy consumption per route

The goal is to find delivery routes that are not only short, but also **energy efficient and practical for drone-based logistics**.

---

## 📌 Overview

Traditional route optimization problems usually aim to minimize total distance.

However, for drone delivery systems, the shortest route is not always the most energy-efficient route.

A drone carrying a heavy package may consume significantly more energy over the same distance than when carrying a lighter payload.

This project models such scenarios using an energy-based routing approach.

```text
Delivery Locations
        ↓
Graph Representation
        ↓
Energy Cost Calculation
        ↓
Route Optimization Algorithms
        ↓
Compare Routes
        ↓
Select Energy-Efficient Route
```

---

# 💡 Problem Statement

Given a set of delivery locations, the objective is to determine the route that minimizes the **total energy consumed by the drone** while visiting all required locations.

Unlike conventional TSP, where the optimization objective is:

```text
Minimize Total Distance
```

this project focuses on:

```text
Minimize Total Energy Consumption
```

Energy usage depends on multiple factors including:

- Distance travelled
- Current payload
- Energy cost factor
- Base drone consumption
- Battery availability

This creates a more realistic version of the route optimization problem.

---

# 🔋 Energy Consumption Model

One of the key features of this project is its custom energy model.

The energy consumed between two locations is calculated using:

```text
Energy = Base Energy + Distance × Energy Factor × (1 + Payload Weight)
```

Where:

| Parameter | Description |
|---|---|
| `Base Energy` | Minimum energy consumed during movement |
| `Distance` | Distance between two locations |
| `Energy Factor` | Energy cost per unit distance |
| `Payload Weight` | Current weight carried by the drone |

This makes route cost dynamic because the energy required to travel depends on both **distance and payload**.

---

# 🧠 Optimization Algorithms

The project implements multiple algorithms to compare different route optimization strategies.

## 1. Greedy Algorithm

The drone repeatedly chooses the next location with the lowest immediate cost.

### Advantages

- Very fast
- Simple implementation
- Suitable for larger inputs

### Limitation

The locally best decision may not produce the globally optimal route.

```text
Time Complexity ≈ O(n²)
```

---

## 2. Exact TSP

An exact approach evaluates possible route combinations to determine the optimal route.

Depending on implementation, this can use:

- Brute Force
- Dynamic Programming

### Advantages

- Produces the optimal solution
- Useful as a benchmark for evaluating other algorithms

### Limitation

Computational cost increases rapidly as the number of delivery locations grows.

Typical brute-force complexity:

```text
O(n!)
```

Dynamic programming approaches can reduce this significantly but still remain expensive for large datasets.

---

## 3. Approximation Algorithm

The approximation approach attempts to achieve a balance between:

```text
Solution Quality ↔ Computation Time
```

It aims to produce routes close to the optimal solution without the computational cost of exact TSP.

This makes it more practical for larger delivery networks.

---

# 📊 Algorithm Comparison

The system allows multiple algorithms to be compared based on:

| Algorithm | Speed | Solution Quality | Scalability |
|---|---|---|---|
| Greedy | High | Moderate | High |
| Exact TSP | Low | Optimal | Low |
| Approximation | Medium | Near Optimal | Medium / High |

This demonstrates an important concept in algorithm design:

> Better accuracy often comes at the cost of higher computation time.

---

# ⚙️ Features

### 🚁 Energy-Aware Route Optimization

Routes are selected based on estimated energy consumption rather than only geographical distance.

### 📦 Payload-Aware Energy Calculation

Energy consumption changes depending on the payload carried by the drone.

### 🧠 Multiple Algorithms

The project provides several optimization strategies for comparison.

### 📊 Performance Comparison

Different algorithms can be evaluated based on:

- Total route distance
- Energy consumed
- Execution time
- Route quality

### ⚡ Efficient C Implementation

Core optimization algorithms are implemented in **C** for high-performance computation.

### 🌐 Node.js Integration

Node.js can be used as an integration layer to expose the optimization engine to external applications.

---

# 🏗️ Project Architecture

```text
                 ┌───────────────────────┐
                 │   Delivery Locations  │
                 └───────────┬───────────┘
                             │
                             ▼
                 ┌───────────────────────┐
                 │   Graph Construction  │
                 └───────────┬───────────┘
                             │
                             ▼
                 ┌───────────────────────┐
                 │     Energy Model      │
                 └───────────┬───────────┘
                             │
          ┌──────────────────┼──────────────────┐
          │                  │                  │
          ▼                  ▼                  ▼
 ┌────────────────┐ ┌────────────────┐ ┌────────────────┐
 │ Greedy Solver  │ │ Exact TSP      │ │ Approximation  │
 │                │ │ Solver         │ │ Solver         │
 └────────┬───────┘ └────────┬───────┘ └────────┬───────┘
          │                  │                  │
          └──────────────────┼──────────────────┘
                             │
                             ▼
                  ┌─────────────────────┐
                  │ Route Comparison    │
                  └──────────┬──────────┘
                             │
                             ▼
                  ┌─────────────────────┐
                  │ Best Energy Route   │
                  └─────────────────────┘
```

---

# 📂 Project Structure

```text
daa/
│
├── src/
│   └── backend/
│       ├── graph.c
│       ├── graph.h
│       │
│       ├── energy_model.c
│       ├── energy_model.h
│       │
│       ├── tsp_greedy.c
│       ├── tsp_greedy.h
│       │
│       ├── tsp_exact.c
│       ├── tsp_exact.h
│       │
│       ├── tsp_approx.c
│       ├── tsp_approx.h
│       │
│       └── main.c
│
├── bin/
│   └── optimizer.exe
│
├── build.bat
├── package.json
├── node_modules/
└── README.md
```

---

# 🧩 Module Description

### `graph.c / graph.h`

Responsible for:

- Graph representation
- Delivery location management
- Distance storage
- Edge handling

---

### `energy_model.c / energy_model.h`

Contains the energy consumption logic.

Responsible for calculating route energy based on:

- Distance
- Payload
- Energy factors

---

### `tsp_greedy.c / tsp_greedy.h`

Implements the greedy route optimization strategy.

---

### `tsp_exact.c / tsp_exact.h`

Implements the exact Travelling Salesman Problem solver.

Used as a benchmark to identify the theoretically optimal route.

---

### `tsp_approx.c / tsp_approx.h`

Implements an approximation-based route optimization algorithm.

Designed to provide better scalability than exact TSP.

---

### `main.c`

The entry point of the C optimization program.

Responsible for:

- Initializing delivery data
- Calling optimization algorithms
- Comparing results
- Displaying the final route and energy consumption

---

# 🚀 Getting Started

## Prerequisites

Make sure the following tools are installed:

```text
C Compiler
Node.js
npm
```

For Windows, GCC can be installed using environments such as MinGW.

---

# ▶️ Run the Precompiled Executable

Navigate to the binary directory:

```bash
cd bin
```

Run:

```bash
optimizer.exe
```

---

# 🔨 Build from Source

Navigate to the project directory:

```bash
cd daa
```

Run:

```bash
build.bat
```

The build script compiles the C source files and generates the optimizer executable.

---

# 🌐 Optional Node.js Integration

Install dependencies:

```bash
npm install
```

Start the Node.js application:

```bash
npm start
```

Node.js can serve as a middleware or backend layer for integrating the C optimization engine with:

- Web applications
- APIs
- Dashboards
- Simulation interfaces

---

# 📈 Example Workflow

Consider a drone that must deliver packages to four locations.

```text
Warehouse
   │
   ├── Location A
   ├── Location B
   ├── Location C
   └── Location D
```

The system calculates the energy cost between possible routes.

For example:

```text
Route 1:
Warehouse → A → B → C → D → Warehouse

Route 2:
Warehouse → C → A → D → B → Warehouse
```

Even if Route 1 has a smaller total distance, Route 2 could consume less energy depending on when heavier packages are delivered.

This demonstrates why:

```text
Shortest Route ≠ Most Energy-Efficient Route
```

---

# ⏱️ Algorithmic Trade-Offs

This project demonstrates one of the most important concepts in algorithm design.

### Exact algorithms

Provide:

```text
Maximum Accuracy
```

but require:

```text
Higher Computation Time
```

### Approximation algorithms

Provide:

```text
Good Solution Quality
```

while reducing:

```text
Execution Time
```

### Greedy algorithms

Provide:

```text
Very Fast Results
```

but may sacrifice:

```text
Global Optimality
```

---

# 📈 Future Enhancements

The project can be extended significantly to simulate real-world drone logistics.

### 🧬 Genetic Algorithm

Use evolutionary optimization techniques to solve larger delivery networks.

### 🔁 2-Opt / 3-Opt Optimization

Improve existing routes by iteratively replacing inefficient edges.

### 🌦️ Weather-Aware Energy Modeling

Include environmental factors such as:

- Wind speed
- Wind direction
- Rain
- Temperature

### 🔋 Battery Constraint Handling

Prevent routes that exceed the drone's battery capacity.

Possible strategy:

```text
Battery Low
     ↓
Nearest Charging Station
     ↓
Recharge
     ↓
Resume Delivery
```

### 🗺️ Real-World Map Integration

Use real geographical data and maps to calculate actual travel distances.

### 🚁 Multi-Drone Optimization

Extend the system from a single drone to an entire delivery fleet.

### 📦 Dynamic Payload Modeling

Update payload weight after each package delivery to calculate more realistic energy consumption.

### ⚡ Charging Station Optimization

Determine where drones should recharge while minimizing route delays.

---

# 🎯 Key Learnings

This project demonstrates practical applications of several important concepts:

- Travelling Salesman Problem
- Graph algorithms
- Greedy algorithms
- Exact optimization
- Approximation algorithms
- Algorithm complexity analysis
- Energy-based cost modeling
- Modular programming in C
- C and Node.js integration
- Performance vs accuracy trade-offs

---

# 🧑‍💻 Tech Stack

| Technology | Purpose |
|---|---|
| **C** | Core optimization algorithms |
| **Node.js** | Backend / integration layer |
| **Graph Data Structures** | Delivery network representation |
| **DSA** | Route optimization logic |
| **Batch Scripts** | Project compilation |

---

# ⭐ Why This Project Stands Out

Most beginner TSP projects solve only one problem:

```text
Find the shortest route.
```

This project asks a more realistic question:

```text
What route requires the least energy?
```

It combines:

- Graph algorithms
- Route optimization
- Energy modeling
- Multiple algorithmic approaches
- Performance analysis
- Real-world delivery constraints

This makes the project a practical application of **Design and Analysis of Algorithms** rather than just a theoretical TSP implementation.

---

# 👩‍💻 Author

**Rishika Shrivastava**

---

# 📜 License

This project was created for **educational and research purposes**.

---

# 🔥 Final Thought

> **Not every shortest path is energy-efficient — and efficient drone delivery requires optimizing both distance and energy.**
