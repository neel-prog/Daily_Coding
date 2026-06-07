#Neel Kiran Sankpal
import pyshark

protocol_count = {}

def update_stats(protocol):
    if protocol in protocol_count:
        protocol_count[protocol] += 1
    else:
        protocol_count[protocol] = 1


print("Starting PyShark capture... Press Ctrl+C to stop.\n")

capture = pyshark.LiveCapture(interface='Wi-Fi')

try:
    for packet in capture.sniff_continuously():
        print("\n================ PACKET =================")

        try:
            print("Source:", packet.ip.src)
            print("Destination:", packet.ip.dst)
            print("Protocol:", packet.transport_layer)

            update_stats(packet.transport_layer)

            print("Protocol Stats:", protocol_count)

        except AttributeError:
            print("Non-IP packet detected")

except KeyboardInterrupt:
    print("\nStopped capture.")
    print("Final Stats:", protocol_count)