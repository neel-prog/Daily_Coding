# 🌐 Website Link Scraper using Beautiful Soup

A simple Python web scraper that extracts all hyperlinks from a webpage using **Requests** and **Beautiful Soup**.

## 📖 Overview

This project demonstrates the fundamentals of web scraping in Python by connecting to a website, parsing its HTML content, and extracting all available links.

The scraper targets the practice website **Books to Scrape** and displays every hyperlink found on the page.

---

## 🚀 Features

✅ Sends HTTP requests to a website

✅ Parses HTML content using Beautiful Soup

✅ Extracts all anchor (`<a>`) tags

✅ Displays discovered links in a numbered format

✅ Handles connection and request errors gracefully

---

## 🛠 Technologies Used

* Python 3
* Requests
* Beautiful Soup 4 (bs4)

---

## 📂 Project Structure

```text
Web_Scraper/
├── Web Scraper.py
└── README.md
```

---

## ⚙️ Installation

Install the required packages:

```bash
pip install requests beautifulsoup4
```

---

## ▶️ Usage

Run the script:

```bash
python scraper.py
```

Example Output:

```text
Scraped Links from https://books.toscrape.com/

1. index.html
2. catalogue/category/books/travel_2/index.html
3. catalogue/category/books/mystery_3/index.html
...
```

---

## 🎯 Learning Objectives

This project helped me understand:

* HTTP requests and responses
* HTML parsing
* Web scraping fundamentals
* Error handling in Python
* Working with third-party libraries

---

## 👨‍💻 Author

**Neel Kiran Sankpal**

Student | Python Enthusiast | Networking & Cybersecurity Learner

---

## 📌 Future Improvements

* Save results to a CSV file
* Scrape book titles and prices
* Follow links recursively
* Export data to JSON format
* Add command-line arguments
