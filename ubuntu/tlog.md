Thanks to: https://github.com/Scribery/tlog.
Terminal I/O logger

Here’s a step-by-step guide to set up tlog for capturing terminal commands and output:

Step 1: Install tlog

Install the tlog package:

```
sudo apt update
sudo apt install tlog
```

Confirm the installation:
```
tlog-rec-session --version
```
This should display the installed version of tlog.

Step 2: Configure tlog

tlog integrates with PAM or can be set as the default shell for specific users. Choose the method that suits your needs:

### Option 1: Configure PAM for Session Recording

Open the PAM configuration for login shells:
```
sudo nano /etc/pam.d/sshd
```

Add the following line at the end of the file:
```
session    required    pam_tty_audit.so enable=* log_passwd=0
```

This setup enables tlog to capture terminal commands and output when users log in via SSH.

### Option 2: Set tlog as the Default Shell

Set tlog-rec-session as the default shell for users whose sessions you want to record:
```
sudo usermod --shell /usr/bin/tlog-rec-session <username>
```

Replace <username> with the specific user account you want to monitor.
To verify, log in as the user and confirm that tlog is active. The session will be recorded.

Step 3: Configure Log Storage

tlog logs to the systemd journal by default, but you can configure it to log via syslog for centralized logging.
Open /etc/tlog/tlog.conf (create it if it doesn’t exist):
```
sudo nano /etc/tlog/tlog.conf
```

Add the following configuration to forward logs to syslog:
```
{
    "destination": "syslog",
    "syslog": {
        "facility": "auth",
        "level": "info"
    }
}
```

Save and close the file.

Step 4: Forward Logs to a Central Server (Optional)

Edit /etc/rsyslog.conf to forward logs:
```
*.* @<CENTRAL_SERVER_IP>:514
```

Restart the rsyslog service:
```
sudo systemctl restart rsyslog
```
Step 5: Test the Setup

Log in to the server as the monitored user.
Run some commands.
Check the logs:
If using systemd journal:
```
sudo journalctl -u tlog
```

If using syslog:
```
cat /var/log/auth.log
```

Step 6: Secure Access to Logs

Restrict access to logs to prevent unauthorized users from viewing sensitive data:
```
sudo chmod 600 /var/log/auth.log
sudo chown root:root /var/log/auth.log
```
Optional Enhancements:
Rotate Logs: Use logrotate to prevent excessive log growth.
Analyze Logs: Forward logs to a log analysis platform (e.g., Grafana + Loki or ELK Stack).
