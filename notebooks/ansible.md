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

![Ansible Official Docs](https://docs.ansible.com/ansible/latest/index.html)

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

```shell
ansible-playbook sample.yml --syntax-check
```

- how to run a specific command on nodes?

```shell
ansible linux -a "cat /etc/os-release"
```

- how do you run a playbook?

```shell
ansible-playbook sample.yml
```

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

## Ansible Playbooks

- A playbook enables us to take our group of servers and perform configuration and installation tasks against that group
- Their structure looks like the following: Playbook > Plays > Tasks
- They're written in YAML format

```yaml
- name: Simple Play
  hosts: localhost
  connection: local
  tasks:
    - name: Ping me
      ping:
    - name: print os
      debug:
        msg: "{{ ansible_os_family }}"
```

### Ansible Galaxy and roles

roles are used to group different groups of assets into categories that are similar and share common tasks (webservers/loadbalanceers...)

This is done using the ansible-galaxy command which created a file structure that will house the different yaml files:

```shell
root@ansible-vm-1:~# ansible-galaxy init roles/webservers
- Role roles/webservers was created successfully
root@ansible-vm-1:~# tree
├── playbook.yml
├── roles
│   └── webservers
│       ├── README.md
│       ├── defaults
│       │   └── main.yml
│       ├── files
│       ├── handlers
│       │   └── main.yml
│       ├── meta
│       │   └── main.yml
│       ├── tasks
│       │   └── main.yml
│       ├── templates
│       ├── tests
│       │   ├── inventory
│       │   └── test.yml
│       └── vars
│           └── main.yml

[ansible_architecture](../assets/ansible/ansible_architecture.png)

- How does variable interpolation work in ansible?
  - Through the jinja template style of {{ variable_name }}
- How to run tasks conditionally?
  - We use the "when" field in the task

```yml
tasks:
  - name: "shut down Debian flavoured systems"
    command: /sbin/shutdown -t now
    when: ansible_os_family == "Debian"
```

- what is the difference between handlers and tasks in ansible?
  - handlers are just a special type of task that only run when they are triggered by the "notified" directive
  - in the below example you can see that the ansible playbook only runs a task to write to teh index.html file if
  the apache service got restarted

```yaml
- name: write a basic index.html file
  template:
    src: templates/index.html.j2
    dest: /var/www/html/index.html
  notify:
  - restart apache
```

### How to tydi up a playbook

You can split a playbook into folders for handlers, tasks and templates and have it reference yaml files in those
folder that will contain the various components of the playbook.

The below structure is a usefull example.

```shell
root@ansible-vm-1:~/ansible_sandbox/scenario2# tree
.
├── handlers
│   └── main.yml
├── playbook2.yml
├── tasks
│   └── apache2_install.yml
└── templates
    ├── index.html.j2
    └── ports.conf.j2

3 directories, 5 files
```

The playbook2.yml file would import tasks using the below syntax:

```yaml
- hosts: linux
  become: yes
  vars:
    http_port: 8000
    https_port: 4443
    html_welcome_msg: "Hello 90DaysOfDevOps - Welcome to Day 66!"
  tasks:
  - import_tasks: tasks/apache2_install.yml

  handlers:
  - import_tasks: handlers/main.yml
```

## Ansible Galaxy

In scanrios where we have more specific functions for each server (loadbalancer, database servers...) we can use
ansible-galaxy to create roles and manage them in shared repositories

```shell
root@ansible-vm-1:~/ansible_sandbox/scenario3# ansible-galaxy init roles/apache2
- Role roles/apache2 was created successfully
root@ansible-vm-1:~/ansible_sandbox/scenario3# tree
.
└── roles
    └── apache2
        ├── README.md
        ├── defaults
        │   └── main.yml
        ├── files
        ├── handlers
        │   └── main.yml
        ├── meta
        │   └── main.yml
        ├── tasks
        │   └── main.yml
        ├── templates
        ├── tests
        │   ├── inventory
        │   └── test.yml
        └── vars
            └── main.yml

10 directories, 8 files
```

The playbook will import the roles instead of the tasks (as compared to playbook2).

```yaml
- hosts: linux
  become: yes
  vars:
    http_port: 8000
    https_port: 4443
    html_welcome_msg: "Hello 90DaysOfDevOps - Welcome to Day 66! This new version comes from ansible-galaxy"
  roles:
    - apache2
```

We'll create some more role for all servers (common) and load balancer (ngix)


```shell
root@ansible-vm-1:~/ansible_sandbox/scenario3# ansible-galaxy init roles/common
- Role roles/common was created successfully
root@ansible-vm-1:~/ansible_sandbox/scenario3# ansible-galaxy init roles/ngix
- Role roles/ngix was created successfully
root@ansible-vm-1:~/ansible_sandbox/scenario3# tree
.
├── playbook3.yml
└── roles
    ├── apache2
    │   ├── README.md
    │   ├── defaults
    │   │   └── main.yml
    │   ├── files
    │   ├── handlers
    │   │   └── main.yml
    │   ├── meta
    │   │   └── main.yml
    │   ├── tasks
    │   │   ├── apache2_install.yml
    │   │   └── main.yml
    │   ├── templates
    │   │   ├── index.html.j2
    │   │   └── ports.conf.j2
    │   ├── tests
    │   │   ├── inventory
    │   │   └── test.yml
    │   └── vars
    │       └── main.yml
    ├── common
    │   ├── README.md
    │   ├── defaults
    │   │   └── main.yml
    │   ├── files
    │   ├── handlers
    │   │   └── main.yml
    │   ├── meta
    │   │   └── main.yml
    │   ├── tasks
    │   │   └── main.yml
    │   ├── templates
    │   ├── tests
    │   │   ├── inventory
    │   │   └── test.yml
    │   └── vars
    │       └── main.yml
    └── ngix
        ├── README.md
        ├── defaults
        │   └── main.yml
        ├── files
        ├── handlers
        │   └── main.yml
        ├── meta
        │   └── main.yml
        ├── tasks
        │   └── main.yml
        ├── templates
        ├── tests
        │   ├── inventory
        │   └── test.yml
        └── vars
            └── main.yml

28 directories, 28 **files**
```
