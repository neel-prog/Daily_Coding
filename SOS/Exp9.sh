#!/bin/bash

echo "===== OS HARDENING ====="

echo
echo "1. Current Host Information"
hostnamectl

echo
echo "2. Running Services"
systemctl --type=service --state=running

echo
echo "3. Disabling Unused Services"

sudo systemctl disable --now telnet.socket 2>/dev/null
sudo systemctl disable --now cups.service 2>/dev/null
sudo systemctl disable --now avahi-daemon.service 2>/dev/null

echo "Unused services disabled where available."

echo
echo "4. SSH Configuration"

sudo cp /etc/ssh/sshd_config /etc/ssh/sshd_config.backup

sudo sed -i 's/^#*PermitRootLogin.*/PermitRootLogin no/' /etc/ssh/sshd_config
sudo sed -i 's/^#*PasswordAuthentication.*/PasswordAuthentication yes/' /etc/ssh/sshd_config
sudo sed -i 's/^#*X11Forwarding.*/X11Forwarding no/' /etc/ssh/sshd_config

echo "SSH configuration updated."

echo
echo "5. Testing SSH Configuration"

sudo sshd -t

if [ $? -eq 0 ]
then
    echo "SSH configuration is valid."
    sudo systemctl restart ssh
else
    echo "SSH configuration contains errors."
fi

echo
echo "6. SSH Service Status"
sudo systemctl status ssh --no-pager

echo
echo "7. File Permission Hardening"

sudo chmod 600 /etc/ssh/sshd_config
sudo chmod 644 /etc/passwd
sudo chmod 640 /etc/shadow

echo "File permissions updated."

echo
echo "8. Firewall Status"

if command -v ufw >/dev/null 2>&1
then
    sudo ufw status
else
    sudo iptables -L -n
fi

echo
echo "OS Hardening Completed."
                                      