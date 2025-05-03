# Auto-Cart
# 🛒 Auto Cart – Smart Shopping Cart using RFID and Raspberry Pi
# Date of start of model - 7th Sept 2024(V1) , 7th Dec 2024(V2)
# Date of end of model - 14th Sept 2024(V1) , 14th Dec 2024(V2)

Auto Cart is a smart shopping cart system designed to automate the billing process in supermarkets using **RFID technology**, **Raspberry Pi**, and **Python**. It eliminates manual scanning and long queues by automatically reading product information and generating the bill in real time.

## 📦 Features

- 📡 **RFID-based Product Scanning** – Instantly scans RFID tags attached to items.
- 💻 **Raspberry Pi & Arduino Integration** – Arduino Collects the data through RFID and raspberry pi interprets the data and shows the bill through software.
- 🧾 **Automatic Bill Generation** – Creates and displays the bill once the billing RFID is scanned.
- 🖥️ **Interactive GUI using Tkinter** – Shows product name, price, and total.
- 💰 **Multiple Payment Options** – Supports **Cash** and **UPI** payments (QR Code shown).
- 🙏 **Thank You Screen** – Displays a final message after successful payment.
- 🔄 **Restart Option** – Clears cart and restarts the session for the next user.

## 🛠️ Tech Stack

- **Hardware:**
  - Raspberry Pi 3B+
  - Arduino Uno
  - RFID RC522 Module (13.56 MHz)
  - 16x2 LCD (I2C)
  - 0.96" OLED Display
  - TFT Display (Optional)
- **Software:**
  - Python 3
  - Tkinter (GUI)
  - RPi.GPIO / adafruit libraries (if using GPIO input)

## 📷 Images of the Model

https://drive.google.com/file/d/1hb2IXnTJx3ekiJiqWe55237rDms-YO1H/view?usp=drive_link

## 🧰 How It Works

1. Products with RFID tags are placed into the cart.
2. RFID reader (connected to Arduino) scans and displays product on the oled.
3. Python GUI receives data and displays item name and price.
4. When **Checkout button is clicked** the bill is generated.
5. The customer selects **Cash** or **UPI** payment.
6. If UPI is selected, a QR code is displayed for 100 seconds.
7. After payment, a thank-you message is shown and the system resets.

## 📁 File Structure
Arduino_code - Consists of arduino code
python_code - Consists of python code
