import qrcode

qr_img = qrcode.make("https://www.instagram.com/stephen_takhellambam/")

qr_img.save("Qr.jpg")