#!/bin/bash

echo "-- USER AUTHENTICATION --"

echo "Current User: $(whoami)"
echo "User ID Information:"
id

echo
echo "Logged-in Users:"
who

echo
echo "-- PASSWORD POLICY --"

echo "Password aging information:"
chage -l $(whoami)

echo
echo "Password Policy:"
grep -E "PASS_MAX_DAYS|PASS_MIN_DAYS|PASS_MIN_LEN|PASS_WARN_AGE" /etc/login.defs

echo
echo "-- FIREWALL CONFIGURATION --"

if command -v ufw >/dev/null 2>&1
then
    echo "UFW Firewall Status:"
    sudo ufw status

    echo
    echo "Allowing SSH:"
    sudo ufw allow 22/tcp

    echo "Enabling Firewall:"
    sudo ufw --force enable

    echo
    echo "Updated Firewall Status:"
    sudo ufw status
else
    echo "UFW is not installed."
    echo "Checking iptables:"
    sudo iptables -L -n
fi
                            