from flask import Flask, render_template, request, jsonify
import subprocess

app = Flask(__name__)

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/solve', methods=['POST'])
def solve():
    # Extract maze data from the request
    data = request.json['maze']
    # Call the MazeSolver executable with the maze data as input
    result = subprocess.run(['./MazeSolver'], input=data, text=True, capture_output=True)
    # Parse the output from your executable to a suitable format
    path = result.stdout  # You might need to process this further
    return jsonify({'path': path})

if __name__ == '__main__':
    app.run(debug=True)
