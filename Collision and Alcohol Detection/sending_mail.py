import smtplib
import geocoder

# Notes - Add sender email, password and receiver email before running this code. 

g = geocoder.ip('me')
print(g.latlng)
sender= "sender-email"
password="sender-password"
receive= "receiver-email"
message = f"""
subject:
EMERGENCY! 
MR.XXXXX met with an accident
Please check in this location {g.latlng}
"""
print("its starting to send")
server = smtplib.SMTP_SSL("smtp.gmail.com",465)
server.login(sender,password)
server.sendmail(sender,receive,message)
server.quit()
print('sent ')