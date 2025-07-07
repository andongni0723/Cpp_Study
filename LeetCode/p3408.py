from typing import List
from heapq import *


class TaskManager:

    def __init__(self, tasks: List[List[int]]):
        self.heap = [] # -priority, -taskId, userID
        self.tasks = {} # taskId -> [priority, userId]

        for u, t, p in tasks:
            self.add(u, t, p)

    def add(self, userId: int, taskId: int, priority: int) -> None:
        heappush(self.heap, (-priority, -taskId, userId))
        self.tasks[taskId] = [priority, userId]

    def edit(self, taskId: int, newPriority: int) -> None:
        _, user = self.tasks[taskId]
        self.tasks[taskId] = (newPriority, user)
        heappush(self.heap, (-newPriority, -taskId, user))

    def rmv(self, taskId: int) -> None:
        self.tasks.pop(taskId, None)

    def execTop(self) -> int:
        while self.heap:
            p_neg, t_neg, _ = heappop(self.heap)
            task = self.tasks.get(-t_neg)
            if task and task[0] == -p_neg:
                p, u = task
                self.tasks.pop(-t_neg)
                return u
        return -1


# Your TaskManager object will be instantiated and called as such:
# obj = TaskManager(tasks)
# obj.add(userId,taskId,priority)
# obj.edit(taskId,newPriority)
# obj.rmv(taskId)
# param_4 = obj.execTop()