#!/bin/bash

REPORT="audit_report.txt"

echo "===== SYSTEM AUDIT REPORT =====" > "$REPORT"
echo "Generated on: $(date)" >> "$REPORT"
echo >> "$REPORT"

echo "===== SYSTEM INFORMATION =====" >> "$REPORT"
hostnamectl >> "$REPORT" 2>/dev/null
echo >> "$REPORT"

echo "===== RECENT LOGIN ACTIVITY =====" >> "$REPORT"
last -n 10 >> "$REPORT" 2>/dev/null
echo >> "$REPORT"

echo "===== FAILED LOGIN ATTEMPTS =====" >> "$REPORT"
lastb -n 10 >> "$REPORT" 2>/dev/null
echo >> "$REPORT"

echo "===== SSH LOGIN ACTIVITY =====" >> "$REPORT"
journalctl -u ssh --since "24 hours ago" --no-pager >> "$REPORT" 2>/dev/null
echo >> "$REPORT"

echo "===== AUTHENTICATION FAILURES =====" >> "$REPORT"
journalctl --since "24 hours ago" --no-pager | grep -Ei \
"failed|failure|authentication failure|invalid user|incorrect password" >> "$REPORT"
echo >> "$REPORT"

echo "===== SUDO ACTIVITY =====" >> "$REPORT"
journalctl --since "24 hours ago" --no-pager | grep -Ei \
"sudo|COMMAND=" >> "$REPORT"
echo >> "$REPORT"

echo "===== SUSPICIOUS SSH ACTIVITY =====" >> "$REPORT"
journalctl -u ssh --since "24 hours ago" --no-pager | grep -Ei \
"failed|invalid user|authentication failure|accepted" >> "$REPORT"
echo >> "$REPORT"

echo "===== AUDITD STATUS =====" >> "$REPORT"

if command -v auditctl >/dev/null 2>&1
then
    sudo auditctl -s >> "$REPORT" 2>/dev/null

    echo >> "$REPORT"
    echo "===== RECENT AUDIT EVENTS =====" >> "$REPORT"
    sudo ausearch --start recent -i >> "$REPORT" 2>/dev/null
else
    echo "auditd is not installed." >> "$REPORT"
fi

echo >> "$REPORT"
echo "===== AUDIT COMPLETE =====" >> "$REPORT"

echo "Audit completed."
echo "Report saved as: $REPORT"
