from abc import ABCMeta, abstractmethod


class AbstractProcessor(object):
    __metaclass__ = ABCMeta

    def __init__(self, in_path, out_path):
        self.in_path = in_path
        self.out_path = out_path

    @abstractmethod
    def process(self):
        raise NotImplementedError

    @abstractmethod
    def input(self, infile):
        raise NotImplementedError

    @abstractmethod
    def output(self, outfile):
        raise NotImplementedError
