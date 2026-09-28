import serial

PORT = "/dev/ttyACM0"
BAUD = 115200

with serial.Serial(PORT, BAUD, timeout=1) as ser:
    print(f"Listening on {PORT} at {BAUD} baud. Ctrl+C to stop.")
    try:
        while True:
            line = ser.readline()
            if not line:
                continue
            print(line.decode("ascii", errors="replace").strip())
    except KeyboardInterrupt:
        print("\nStopped.")