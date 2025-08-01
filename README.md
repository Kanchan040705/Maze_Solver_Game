# Maze_Solver_Game
This project is a C++-based Maze Solver that finds the shortest path in a user-defined grid using graph traversal algorithms.It allows users to create a custom maze by defining walls, a start point, and an end point. The game then uses Breadth-First Search (BFS) to find the shortest path from the start to the end.

**Features**

   1.  Custom maze creation (user-defined grid, walls, start/end points).
   2.  Uses BFS algorithm to find the shortest path.
   3. Visual representation of the maze and the path in the console.
   4. Handles cases where no path is possible.

  **Data Structures & Algorithms Used**

  1. 2D Grid as a graph.
  2. Breadth-First Search (BFS) for shortest path.
  3. Queues for level-order traversal.
  4. Visited and Parent matrices to track state and backtrack the path.

**To Run File**
 
 1. compile main file in vs code i.e. g++ mainn.cpp -o mainn
 2. now run this file by ./mainn
 3. now enter the asked questions and get final answer.
    Input example: 
      Enter number of walls: 6
      Enter wall positions (row col):
      1 1
      1 2
      2 2
      3 2
      3 3
      4 3
      Enter start position (row col): 0 0
      Enter end position (row col): 4 4
4. get desired result.

