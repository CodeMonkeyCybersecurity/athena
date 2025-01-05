https://microk8s.io/docs/getting-started

Skip to main content
Jump to main content
CanonicalMicroK8s
Menu
Search documentation
Search
 Toggle side navigation
Get started
On this page
What you’ll need
What you’ll need
An Ubuntu 22.04 LTS, 20.04 LTS, 18.04 LTS or 16.04 LTS environment to run the commands (or another operating system which supports snapd - see the snapd documentation). If you don’t have a Linux machine, you can use Multipass (see Installing MicroK8s with Multipass).
MicroK8s runs in as little as 540MB of memory, but to accommodate workloads, we recommend a system with at least 20G of disk space and 4G of memory.
An internet connection
Note: If you don’t meet these requirements, there are additional ways of installing MicroK8s, including additional OS support and an offline deploy. See the alternative install page for details.

Install MicroK8s

MicroK8s will install a minimal, lightweight Kubernetes you can run and use on practically any machine. It can be installed with a snap:
```
sudo snap install microk8s --classic
```
More about setting the channel

Join the group

MicroK8s creates a group to enable seamless usage of commands which require admin privilege. To add your current user to the group and gain access to the .kube caching directory, run the following three commands:
```
sudo usermod -a -G microk8s $USER
mkdir -p ~/.kube
chmod 0700 ~/.kube
```
You will also need to re-enter the session for the group update to take place:
```
su - $USER
```
Check the status

MicroK8s has a built-in command to display its status. During installation you can use the --wait-ready flag to wait for the Kubernetes services to initialise:
```
microk8s status --wait-ready
```
Access Kubernetes

MicroK8s bundles its own version of kubectl for accessing Kubernetes. Use it to run commands to monitor and control your Kubernetes. For example, to view your node:
```
microk8s kubectl get nodes
```
…or to see the running services:
```
microk8s kubectl get services
```
MicroK8s uses a namespaced kubectl command to prevent conflicts with any existing installs of kubectl. If you don’t have an existing install, it is easier to add an alias (append to ~/.bash_aliases) like this:
```
alias kubectl='microk8s kubectl'
```
Deploy an app

Of course, Kubernetes is meant for deploying apps and services. You can use the kubectl command to do that as with any Kubernetes. Try installing a demo app:
```
microk8s kubectl create deployment nginx --image=nginx
```
It may take a minute or two to install, but you can check the status:

microk8s kubectl get pods

Use add-ons

MicroK8s uses the minimum of components for a pure, lightweight Kubernetes. However, plenty of extra features are available with a few keystrokes using “add-ons” - pre-packaged components that will provide extra capabilities for your Kubernetes, from simple DNS management to machine learning with Kubeflow!

To start it is recommended to add DNS management to facilitate communication between services. For applications which need storage, the ‘hostpath-storage’ add-on provides directory space on the host. These are easy to set up:

microk8s enable dns
microk8s enable hostpath-storage
See the full list of addons

Starting and Stopping MicroK8s

MicroK8s will continue running until you decide to stop it. You can stop and start MicroK8s with these simple commands:

microk8s stop

… will stop MicroK8s and its services. You can start again any time by running:

microk8s start

Note that if you leave MicroK8s running, it will automatically restart after a reboot. If you don’t want this to happen, simply remember to run microk8s stop before you power down.

Next steps
One node not enough? Try setting up a MicroK8s cluster.
Want to experiment with alpha releases of Kubernetes? See the documentation on setting channels.
Need to fiddle with the Kubernetes configuration? Find out how to configure the Kubernetes services.
Find out how to run MicroK8s on Windows, macOS or a Raspberry Pi.
Having problems? Check out our troubleshooting section.
Love MicroK8s? Want to contribute or suggest a feature? Give us your feedback.
Find out how Devs, DevOps and businesses really use Kubernetes: Read the latest industry report
Last updated 22 days ago. Help improve this document in the forum.

© 2025 Canonical Ltd.

Legal information
Manage your tracker settings
Report a bug on this site
Ubuntu and Canonical are registered trademarks of Canonical Ltd.