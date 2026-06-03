# Website Link Scraper using BeautifulSoup

## Overview

This project is a Python-based website scraper that extracts all hyperlinks (`<a>` tags) from a given website using the BeautifulSoup library. The program allows users to enter a website URL, scrape available links, display them on the console, and save them to a text file for future reference.

## Features

* User-friendly command-line interaction
* Accepts website URL as input
* Extracts all hyperlinks from a webpage
* Displays scraped links in a numbered format
* Saves extracted links to a text file
* Handles connection and request errors gracefully
* Uses a custom User-Agent to improve compatibility

## Technologies Used

* Python 3
* Requests
* BeautifulSoup4

## Installation

Install the required libraries:

```bash
pip install requests beautifulsoup4
```

## How to Run

1. Clone or download the project.
2. Open a terminal in the project directory.
3. Run the script:

```bash
python Web Scraper.py
```

4. Enter the website URL when prompted.
5. Enter the desired output file name.
6. The scraped links will be displayed and saved to a text file.

## Sample Execution

```text
=== Website Link Scraper ===

Enter website URL: https://books.toscrape.com/
Enter output file name (without extension): links

1. index.html
2. catalogue/category/books_1/index.html
3. catalogue/category/books/travel_2/index.html

Successfully scraped 94 links.
Links saved in 'links.txt'
```

## Project Structure

```text
Website-Scraper/
│
├── Web Scraper.py
├── README.md
└── links.txt
```

## Learning Outcomes

Through this project, the following concepts were implemented:

* Web scraping using BeautifulSoup
* HTTP requests using the Requests library
* Exception handling in Python
* File handling and data storage
* User interaction through command-line input
* HTML parsing and link extraction



## License

This project is developed for educational and learning purposes.
