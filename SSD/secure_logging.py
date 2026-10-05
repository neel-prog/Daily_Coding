import logging
from pathlib import Path


# -----------------------------
# Secure Logging Configuration
# -----------------------------

LOG_DIR = Path("logs")
LOG_DIR.mkdir(exist_ok=True)

LOG_FILE = LOG_DIR / "application.log"

logging.basicConfig(
    filename=LOG_FILE,
    level=logging.INFO,
    format="%(asctime)s | %(levelname)s | %(message)s"
)

logger = logging.getLogger(__name__)


# -----------------------------
# Secure Login Function
# -----------------------------

def login(username, password):

    try:
        if not username or not password:
            logger.warning("Login attempt with missing credentials")
            return False

        # Demo credentials
        if username == "admin" and password == "admin123":
            logger.info("Successful login for user: %s", username)
            return True

        logger.warning("Failed login attempt for user: %s", username)
        return False

    except Exception:
        # Do not expose internal error details
        logger.exception("Unexpected error during login")
        return False


# -----------------------------
# Main Program
# -----------------------------

try:

    username = input("Enter username: ")
    password = input("Enter password: ")

    if login(username, password):
        print("Login successful.")
    else:
        print("Invalid username or password.")

except KeyboardInterrupt:
    logger.info("Application interrupted by user")
    print("\nApplication terminated.")

except Exception:
    logger.exception("Unexpected application error")
    print("An unexpected error occurred.")
