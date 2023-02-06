# Ansible

- what is ansible?
  - configuration and orchestration for IT assets
  - uses a YAML file to describe the verious playbook?
- why ansible?
  - you can write code that describes the state that you want you assets to be in and thus create automated ways of managing
  large sets of servers.
- how do you install ansible?
  - on most UNIX style machines you can install ansbile from pypi. However on some distributions you can use other package
  managers

```shell
# Most scenarios
python3 -m pip install --user ansible

# On Fedora
sudo dnf install ansible 

# On CentOS
sudo yum install epel-release
sudo yum install ansible

# On Ubuntu
sudo apt install software-properties-common
sudo apt install add-app-repository --yes --update ppa:ansible/ansible
sudo apt install ansible
```

- what is a playbook in ansible?
  - it a fancy way of saying a collection of configuration files used by ansible. they are written in YAML

```YAML
---
- name: [playbook_name]
  hosts: [host_group_name_from_inventory]
  remote_user: root
  become: true (flag to show that its a priviliged access)
  tasks:
    - name: install httpd
      yum:
        name: http
        state: latest
    - name: run httpd
      service:
            name: httpd
            state: started
    - name: create content
      copy:
        content: /some/path/to/file
        dest: /var/www/html/index.html 
```

- how do you check the syntax of a playbook?
  - ansible-playbook sample.yml --syntax-check
- how do you run a playbook?
  - ansible-playbook sample.yml
- what are the common tasks that can be accomplished with ansible?
- how are the benefits of ansible measure?
- how does ansible communicate with the nodes from the master?
  - ansible uses ssh to communicate with the nodes?
- what does it mean to be a push configuration tool?
  - push based configuration management means that you don't have to install an agent on each node.
  - an agent is a small software that runs on every node that needs to be managed and at regular interval will **pull**
  the configs from the server. If there is a discrepancy then the new version of configs will be applied. Cheff and Puppet
  are examples of such systems.
  - on push based config management tools the server will send the configs to the nodes

![pull_vs_push](../assets/ansible/pull_vs_push.png)

- what is an inventory in ansible and how is it configured?
  - its a list of hosts ansible will mananage the config for. It can be in INI or YAML format and can be organised into
  different sub-groups. The list can be an IP address or a FQDN (fully qualified domain name)

```INI
#INI format
[webservers]
hostname.domain.com

[dbservers]
192.168.1.100
```

- what is the architecture ansible:
  - local machine, where ansible is installed
  - modules which are configuration files. each module consists of palybooks
  - invetory, a list of nodes to control
  - each node is connected to via ssh clients

![ansible_architecture](../assets/ansible/ansible_architecture.png)