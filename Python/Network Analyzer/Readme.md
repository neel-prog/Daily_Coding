# Python Network Analyzer using PyShark

A simple real-time network packet analyzer built using **Python** and **PyShark**. This project captures live network traffic, extracts useful packet information, and maintains protocol statistics.

## Features

- Captures live network packets from a selected network interface.
- Displays:
  - Source IP Address
  - Destination IP Address
  - Transport Layer Protocol
- Handles non-IP packets gracefully.
- Maintains and displays protocol usage statistics.
- Stops safely using `Ctrl + C` and prints final statistics.

## Technologies Used

- Python 3
- PyShark
- TShark (Wireshark command-line tool)
- Asyncio

## Prerequisites

Before running this project, ensure the following are installed:

### 1. Python

Download and install Python from:
https://www.python.org/downloads/

### 2. Wireshark and TShark

Download Wireshark:
https://www.wireshark.org/download.html

During installation, make sure **TShark** is selected.

Verify installation:

```bash
tshark -v
```

### 3. Install PyShark

```bash
pip install pyshark
```

## Finding Network Interfaces

To list available interfaces:

```bash
tshark -D
```

Example output:

```text
1. Ethernet
2. Wi-Fi
3. Loopback
```

Update the interface name in the code:

```python
capture = pyshark.LiveCapture(
    interface='Wi-Fi'
)
```

Replace `'Wi-Fi'` with your system's interface if required.

## Project Structure

```text
.
├── network.py
└── README.md
```

## How to Run

Execute the script:

```bash
python network.py
```

Output example:

```text
Starting PyShark capture... Press Ctrl+C to stop.

================ PACKET =================
Source: 192.168.1.5
Destination: 142.250.183.78
Protocol: TCP

Protocol Stats:
  TCP: 12
  UDP: 4
```

To stop capturing packets, press:

```text
Ctrl + C
```

Final statistics will be displayed:

```text
Stopped capture.

Final Statistics:
TCP: 45
UDP: 18
OTHER: 7
```

## How It Works

1. Creates a dedicated asyncio event loop.
2. Starts a live packet capture using PyShark.
3. Continuously listens for incoming packets.
4. Extracts:
   - Source IP
   - Destination IP
   - Transport Protocol
5. Updates protocol counters.
6. Displays live statistics.
7. Handles non-IP packets without crashing.

## Limitations

- Requires administrator privileges in some operating systems.
- Works only if TShark is properly installed and accessible.
- Currently displays only basic packet information.
- Does not save captured packets to a file.

## Future Improvements

- Graphical User Interface (GUI).
- Export packet data to CSV or JSON.
- Packet filtering support.
- Bandwidth monitoring.
- Top talkers analysis.
- Protocol visualization charts.

## Author

**Neel Kiran Sankpal**

---

This project was developed as a learning exercise to understand packet capturing, protocol analysis, and real-time network monitoring using Python.