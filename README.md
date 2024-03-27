# MazeSolver Web Application

The MazeSolver is a web application that allows users to solve mazes through a simple web interface. It leverages a C++ backend for maze-solving logic and a Flask-based web server for handling web requests.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

Before you begin, ensure you have the following installed on your system:
- Python 3.x
- Flask
- A C++ compiler (like GCC or Clang)

### Installing

A step-by-step series of examples that tell you how to get a development environment running.

1. **Clone the repository**

    ```
    git clone https://github.com/fatinm1/Maze-Solver-
    cd MazeSolver
    ```

2. **Set up a Python virtual environment (optional but recommended)**

    ```
    python3 -m venv venv
    source venv/bin/activate  # On Windows use `venv\Scripts\activate`
    ```

3. **Install Flask**

    ```
    pip install Flask
    ```

4. **Compile the C++ Maze Solver**

    Navigate to the directory containing your C++ files and compile them into an executable.

    ```
    g++ -o MazeSolver MazeSolver.cpp driver.cpp -I.
    ```

5. **Run the Flask application**

    ```
    flask run
    ```
   
   Or

    ```
    python app.py
    ```

    Visit `http://127.0.0.1:5000/` in your web browser to view the application.

## Usage

The application solves mazes represented as a grid of cells, where each cell can either be a wall or a path. The user inputs a maze, and the application returns the path from the start point to the end point, if one exists.


## Authors

* **Fatin Mojumder** - *Initial work* - [fatinm1](https://github.com/fatinm1)


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
