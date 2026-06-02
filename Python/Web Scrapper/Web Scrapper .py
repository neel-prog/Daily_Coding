#Implementation of website scrapper using beautiful soup
#Neel Kiran Sankpal
#24CC1002
import requests
from bs4 import BeautifulSoup

url = "https://books.toscrape.com/"

headers = {
    "User-Agent": "Mozilla/5.0"
}

try:
    response = requests.get(url, headers=headers, timeout=10)

    if response.status_code == 200:
        soup = BeautifulSoup(response.text, "html.parser")

        links = soup.find_all("a")

        print(f"\nScraped Links from {url}:\n")

        count = 0
        for link in links:
            href = link.get("href")
            if href:
                count += 1
                print(f"{count}. {href}")

        if count == 0:
            print("No links found.")

    else:
        print("Failed! Status Code:", response.status_code)

except requests.exceptions.RequestException as e:
    print("Error:", e)