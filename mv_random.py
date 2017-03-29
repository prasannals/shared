import os
import shutil
from numpy import random

def mv_random(source, destination, num_to_move):
    '''
    ********* IMPORTANT ***********
    make sure that the destination folder actually exists before this function
    is called
    '''
    fileList = os.listdir(source)
    ranFiles = random.choice(fileList, num_to_move, replace=False)

    ranFiles = [os.path.join(source, f) for f in ranFiles]

    for f in ranFiles:
        shutil.move(f, destination)


def cp_random(source, destination, num_to_move):
    '''
    ********* IMPORTANT ***********
    make sure that the destination folder actually exists before this function
    is called
    '''
    fileList = os.listdir(source)
    ranFiles = random.choice(fileList, num_to_move, replace=False)

    ranFiles = [os.path.join(source, f) for f in ranFiles]

    for f in ranFiles:
        shutil.copy(f, destination)
