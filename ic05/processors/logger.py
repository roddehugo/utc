import logging


class Logger(object):
    instance = False

    @staticmethod
    def logger(name):
        if not Logger.instance:
            logging.basicConfig(
                filename='logs/processors.log',
                format='%(asctime)s <%(name)s> [%(levelname)s] %(message)s',
                level=logging.INFO
            )
            Logger.instance = Logger()
        return logging.getLogger(name)


applogger = Logger.logger
