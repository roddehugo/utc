class MessageException(Exception):

    def __init__(self):
        super(MessageException, self).__init__(self.message)


class EmptyArgumentsError(MessageException):
    message = "Object must be instantiated with at least one argument"

    def __init__(self, klass):
        self.message = '%s %s' % (klass, self.message)
        super(EmptyArgumentsError, self).__init__()


class CookieExpiredError(MessageException):
    message = "Cookie has expired. Please provide a fresh one"

