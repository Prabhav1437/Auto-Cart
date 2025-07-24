import tkinter as tk
from tkinter import ttk
from PIL import Image, ImageTk

items = [
    ("Milk", 30),
    ("Bread", 25),
    ("Eggs", 60),
    ("Butter", 50)
]

class AutoCartApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Auto Cart")
        self.root.geometry("600x400")
        self.root.configure(bg="white")
        self.total = sum(price for _, price in items)
        self.welcome_screen()

    def clear_screen(self):
        for widget in self.root.winfo_children():
            widget.destroy()

    def welcome_screen(self):
        self.clear_screen()
        label = tk.Label(self.root, text="PLEASE PRESS THE BUTTON FOR CHECKOUT", 
                         font=("Arial", 18, "bold"), bg="white", wraplength=550, justify="center")
        label.pack(pady=50)
        ttk.Button(self.root, text="Checkout", command=self.checkout_screen).pack(pady=20)

    def checkout_screen(self):
        self.clear_screen()
        tk.Label(self.root, text="BILLING ITEMS", font=("Arial", 18, "bold"), bg="white").pack(pady=10)
        for name, price in items:
            tk.Label(self.root, text=f"{name} - ₹{price}", font=("Arial", 14), bg="white").pack()
        tk.Label(self.root, text=f"Total: ₹{self.total}", font=("Arial", 16, "bold"), bg="white").pack(pady=10)
        ttk.Button(self.root, text="Proceed to Payment", command=self.payment_screen).pack(pady=20)

    def payment_screen(self):
        self.clear_screen()
        tk.Label(self.root, text="Select Payment Method", font=("Arial", 18, "bold"), bg="white").pack(pady=20)
        ttk.Button(self.root, text="Cash", command=self.thank_you_screen).pack(pady=10)
        ttk.Button(self.root, text="UPI", command=self.qr_screen).pack(pady=10)

    def qr_screen(self):
        self.clear_screen()
        tk.Label(self.root, text="Scan to Pay", font=("Arial", 18, "bold"), bg="white").pack(pady=10)
        image = Image.open("/home/pi/Desktop/qr.jpg")
        image = image.resize((200, 200))
        qr_image = ImageTk.PhotoImage(image)
        label = tk.Label(self.root, image=qr_image, bg="white")
        label.image = qr_image
        label.pack(pady=10)
        self.root.after(10000, self.thank_you_screen)

    def thank_you_screen(self):
        self.clear_screen()
        tk.Label(self.root, text="THANK YOU FOR SHOPPING WITH US!", 
                 font=("Arial", 18, "bold"), bg="white", wraplength=550, justify="center").pack(expand=True)

root = tk.Tk()
app = AutoCartApp(root)
root.mainloop()
