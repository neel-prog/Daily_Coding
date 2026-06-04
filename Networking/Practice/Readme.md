# Cisco Packet Tracer Network Simulation using DHCP and Static Routing

## 📌 Project Overview

This project demonstrates the implementation of a basic enterprise network in Cisco Packet Tracer. The network utilizes **DHCP (Dynamic Host Configuration Protocol)** for automatic IP address assignment and **Static Routing** for communication between multiple networks.

The objective of this project is to understand and implement fundamental networking concepts including IP addressing, DHCP configuration, routing, and network connectivity verification.

---

## 🎯 Objectives

* Configure multiple LANs using IPv4 addressing.
* Implement DHCP for automatic host configuration.
* Configure Static Routing using the `ip route` command.
* Enable communication between different networks.
* Verify network functionality through connectivity testing.

---

## 🛠 Technologies Used

* Cisco Packet Tracer
* IPv4 Addressing
* DHCP
* Static Routing
* Routers
* Switches
* End Devices (PCs)

---

## 🌐 Network Topology

The topology consists of:

* Multiple routers interconnected through serial or Ethernet links.
* Separate LAN segments connected via switches.
* End-user devices configured to obtain IP addresses dynamically through DHCP.

> Add a screenshot of your Packet Tracer topology here.

---

## ⚙️ Configuration Details

### DHCP Configuration

DHCP was configured to automatically assign:

* IP Address
* Subnet Mask
* Default Gateway
* DNS Server (Optional)

Example DHCP Pool Configuration:

```bash
ip dhcp pool LAN1
network 192.168.1.0 255.255.255.0
default-router 192.168.1.1
dns-server 8.8.8.8
```

### Static Routing Configuration

Static routes were configured on routers to enable communication between different networks.

Example:

```bash
ip route 192.168.2.0 255.255.255.0 10.0.0.2
```

General Syntax:

```bash
ip route <destination-network> <subnet-mask> <next-hop-address>
```

---

## 🧪 Testing and Verification

### Verify DHCP Assignment

```bash
ipconfig
```

### Verify Network Connectivity

```bash
ping <destination-ip>
```

### Verify Routing Table

```bash
show ip route
```

Successful ping responses confirmed proper DHCP allocation and routing between networks.

---

## 📚 Concepts Learned

* Network Design Fundamentals
* IPv4 Addressing and Subnetting
* DHCP Configuration and Management
* Static Route Implementation
* Router and Switch Configuration
* Network Troubleshooting

---

## 🚀 Future Enhancements

* Implement Dynamic Routing Protocols (RIP, OSPF, EIGRP)
* Configure VLANs and Inter-VLAN Routing
* Apply Access Control Lists (ACLs)
* Introduce Network Redundancy
* Configure NAT and PAT

---

## 📁 Project Files

```text
├── NetworkTopology.pkt
├── README.md
└── Screenshots/
    └── topology.png
```

---

## 👨‍💻 Author

**Neel Kiran Sankpal**

Computer Engineering Student

---

## 📜 License

This project is intended for educational and learning purposes.
