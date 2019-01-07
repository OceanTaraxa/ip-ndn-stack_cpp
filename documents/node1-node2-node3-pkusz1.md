> ## 最小原型网络环境配置
> - 该配置临时生效，电脑重启之后会丢失
> - node1(192.169.1.1) -> node2(192.169.1.2) -> node3(192.169.1.3) -> pkusz1(192.169.1.4)

- ### 确保各NDN主机的nfd进程已经启动
  > 在本最小原型场景下，pkun1和pkun2为NDN主机，pkun3和hitn1为IP主机

  NDN主机的环境配置以及Face创建等，参见[IP_NDN_STACK 部署脚本](https://github.com/SunnyQjm/ip-ndn-stack_cpp/tree/master/deployment)

  ```bash
  nfd-status
  
  # 如果没有启动则执行下面的命令启动
  nfd-start
  ```
- ### 配置ip及网关
  - node1
    ```bash
    sudo ifconfig enp1s0f0 192.169.1.1
    sudo route add -host 192.169.1.2 dev enp1s0f0
    sudo route add -net 192.169.1.0/24 dev enp1s0f0 gw 192.169.1.2
    ```
  - node2
    ```bash
    sudo ifconfig enp1s0f0 192.169.1.2
    sudo route add -host 192.169.1.1 dev enp1s0f0
    ```
  - node3
    ```bash
    sudo ifconfig enp7s0f3 192.169.1.3
    sudo route add -host 192.169.1.4 dev enp7s0f3
    ```
  - pkusz1
    ```bash
    sudo ifconfig eth1 192.169.1.4
    sudo route add -host 192.169.1.3 dev eth1
    sudo route add -net 192.169.1.0/24 dev eth1 gw 192.169.1.3
    ```
  
  - 测试
    在pkun1上执行：
    ```bash
    ping 192.169.1.2
    ```
    在hitn1上执行：
    ```bash
    ping 192.169.1.3
    ```