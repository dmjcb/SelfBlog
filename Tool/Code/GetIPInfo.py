"""
Description: 
Version: 1.0
Author: dmjcb
Email:  
Date: 2022-04-10 14:34:20
LastEditors: dmjcb
LastEditTime: 2022-07-03 00:38:59
"""

import requests

ip = "172.233.157.41"

r = requests.get("http://ip-api.com/json/" + ip)

print(r.json())
