# By c10udlnk(https://github.com/c10udlnk)
# Enjoy it!

import time
import angr
import sys

def is_successful(state):
    stdout_output=state.posix.dumps(sys.stdout.fileno())
    return b"Good Job." in stdout_output
def should_abort(state):
    stdout_output=state.posix.dumps(sys.stdout.fileno())
    return b"Try again." in stdout_output

t=time.clock()
path_to_binary='./vm'
project=angr.Project(path_to_binary,auto_load_libs=False)
initial_state=project.factory.entry_state()
simulation=project.factory.simgr(initial_state)

# find_address=0x80485DD
# avoid_address=[0x80485EF,0x804855B,0x80485A8]
simulation.one_active.options.add(angr.options.LAZY_SOLVES)
# simulation.explore(find=find_address,avoid=avoid_address)
simulation.explore(find=is_successful,avoid=should_abort)

print('time:',round(time.clock()-t,2),'s')
if simulation.found:
    solution_state=simulation.found[0]
    print(solution_state.posix.dumps(sys.stdin.fileno()))
else:
    raise Exception('Could not find the solution. _0x0_')