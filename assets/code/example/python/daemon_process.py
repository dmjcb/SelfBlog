import time
from multiprocessing import Process

def work():
    for i in range(10):
        print("Work in %s" % (i))
        time.sleep(0.5)


if __name__ == "__main__":
    # 创建子进程
    work_process = Process(target=work)

    # 设置守护进程, 主进程结束后子进程直接销毁
    work_process.daemon = True

    work_process.start()

    time.sleep(1)

    print("主进程结束!")
