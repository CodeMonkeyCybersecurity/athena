https://documentation.wazuh.com/current/cloud-service/your-environment/agents-without-internet.html

Configure NGINX.

Add the following lines to the HTTP section in your NGINX configuration, located in the /etc/nginx/nginx.conf file. This configuration enables Nginx to extract and use the real client IP address from the X-Forwarded-For header and sets restrictions on which real IP addresses are accepted as valid.


http{
...
real_ip_header X-Forwarded-For;
set_real_ip_from nginx_ip;
   }

Add the following block to the end of the NGINX configuration file /etc/nginx/nginx.conf and replace <CLOUD_ID> with the Cloud ID of your environment. This configuration enables stream proxying, where incoming traffic on specific ports is forwarded to the corresponding upstream servers (master or mycluster). This is based on the port numbers, 1515 and 1514 specified in the listen directive.


stream {
  upstream master {
    server <CLOUD_ID>.cloud.wazuh.com:1515;
  }
  upstream mycluster {
    server <CLOUD_ID>.cloud.wazuh.com:1514;
    }
  server {
    listen nginx_ip:1515;
    proxy_pass master;
  }
  server {
    listen nginx_ip:1514;
    proxy_pass mycluster;
  }
}

Restart the NGINX service.


systemctl restart nginx
Enroll your agent with the IP address of the NGINX instance. To learn more about registering agents, see the Enroll agents section.

Example:


WAZUH_MANAGER_IP=<NGINX_IP> WAZUH_PROTOCOL="tcp" \
WAZUH_PASSWORD="<PASSWORD>" \
yum install wazuh-agent