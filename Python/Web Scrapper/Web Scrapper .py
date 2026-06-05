# Website Scraper using BeautifulSoup
# Neel Kiran Sankpal
# 24CC1002

import requests
from bs4 import BeautifulSoup

print("Website Link Scraper")

url = input("Enter website URL: ").strip()
filename = input("Enter output file name (without extension): ").strip() + ".txt"

headers = {
    "User-Agent": "Mozilla/5.0"
}

try:
    response = requests.get(url, headers=headers, timeout=10)

    if response.status_code == 200:
        soup = BeautifulSoup(response.text, "html.parser")

        links = soup.find_all("a")

        count = 0

        with open(filename, "w", encoding="utf-8") as file:
            file.write(f"Scraped Links from {url}\n")
            file.write("=" * 50 + "\n")

            for link in links:
                href = link.get("href")

                if href:
                    count += 1
                    print(f"{count}. {href}")
                    file.write(f"{count}. {href}\n")

        if count == 0:
            print("No links found.")
        else:
            print(f"\nSuccessfully scraped {count} links.")
            print(f"Links saved in '{filename}'")

    else:
        print("Failed! Status Code:", response.status_code)

except requests.exceptions.RequestException as e:
    print("Error:", e)

except Exception as e:
    print("Unexpected Error:", e)