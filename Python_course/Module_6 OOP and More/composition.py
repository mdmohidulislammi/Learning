# a composition has a relation

class CPU:
    def __init__(self, cores)-> None:
        self.cores=cores
        
class RAM:
    def __init__(self, size)-> None:
        self.size=size
        
class HardDrive:
    def __init__(self, capacity)->None:
        self.size=capacity
        
class Computer:
    def __init__(self, cores, ram_size, hd_capacity)-> None:
        self.cpu=CPU(cores)
        self.ram=RAM(ram_size)
        self.hd=HardDrive(hd_capacity)
        
mac=Computer(2, 8, 512)

print(mac)
        