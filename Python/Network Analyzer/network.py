import asyncio # use for older pyshark comment it out if pyshark is newer versions
import pyshark

loop = asyncio.new_event_loop()
asyncio.set_event_loop(loop)

protocol_count = {}

def update_stats(protocol):
    protocol_count[protocol] = protocol_count.get(protocol, 0) + 1

print("Starting PyShark capture... Press Ctrl+C to stop.\n")

capture = pyshark.LiveCapture(
    interface=('Wi-Fi')  #Your Interface| Note:use tshark -D to know your interfaces ;)
)

try:
    for packet in capture.sniff_continuously():
        print("\n============== PACKET ==============")

        try:
            src = packet.ip.src
            dst = packet.ip.dst

            protocol = packet.transport_layer
            if protocol is None:
                protocol = "OTHER"

            print("Source:", src)
            print("Destination:", dst)
            print("Protocol:", protocol)

            update_stats(protocol)

            print("Protocol Stats:")
            for proto, count in protocol_count.items():
                print(f"  {proto}: {count}")

        except AttributeError:
            print("Non-IP packet detected")

except KeyboardInterrupt:
    print("\nStopped capture.")
    print("\nFinal Statistics:")
    for proto, count in protocol_count.items():
        print(f"{proto}: {count}")