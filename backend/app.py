from flask import Flask, request, jsonify

app = Flask(__name__)

# State of pump (0 = OFF, 1 = ON)
pump_state = 0

@app.route('/')
def home():
    return "IoT Solar Cleaner Backend Running"

@app.route('/get_status', methods=['GET'])
def get_status():
    return jsonify({"pump_state": pump_state})

@app.route('/set_pump', methods=['POST'])
def set_pump():
    global pump_state
    data = request.json
    if "state" in data:
        pump_state = int(data["state"])
        return jsonify({"message": "Pump state updated", "pump_state": pump_state})
    return jsonify({"error": "Invalid request"}), 400

if __name__ == '__main__':
    app.run(host="0.0.0.0", port=5000)
