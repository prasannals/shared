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

def create_valid(trainLoc, validSize):
    '''
    trainLoc is the location of the 'train' folder. NOT the location of the
    data set itself
    '''
    classes = os.listdir(trainLoc)
    validLoc = trainLoc + '../valid/'
    validClasses = [validLoc + c + '/' for c in classes]
    trainClasses = [trainLoc + c + '/' for c in classes]

    for source, destination in zip(trainClasses, validClasses):
        os.makedirs(destination)
        mv_random(source, destination, validSize)

def create_sample(dataFolder, trainSize, validSize):
    sampleLoc = dataFolder + 'sample/'

    trainSrc = dataFolder + 'train/'
    trainDest = sampleLoc + 'train/'

    validSrc = dataFolder + 'valid/'
    validDest = sampleLoc + 'valid/'

    srcClasses = os.listdir(trainSrc)
    srcTrainClasses = [trainSrc + c + '/' for c in srcClasses]
    srcValidClasses = [validSrc + c + '/' for c in srcClasses]

    destTrainClasses = [trainDest + c + '/' for c in srcClasses]
    destValidClasses = [validDest + c + '/' for c in srcClasses]


    for src, dest in zip(srcTrainClasses, destTrainClasses):
        os.makedirs(dest)
        cp_random(src, dest,trainSize + validSize)

    create_valid(sampleLoc + 'train/', validSize)
