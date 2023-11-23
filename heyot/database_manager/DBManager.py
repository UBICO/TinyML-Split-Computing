from .models import TestData
import logging
logger = logging.getLogger(__name__)

class DBManager:
    def store_test_data(self, message_uiid, **kwargs):
        """
        The function `store_test_data` stores test data in the database, updating fields from the
        `kwargs` dictionary.
        
        :param message_uiid: The parameter "message_uiid" is used to identify a specific message. It is
        likely a unique identifier for each message in the system.
        """
        logger.info(f"Store Message Data")
        try:
            test, _ = TestData.objects.get_or_create(message_uiid=message_uiid)
            # Update fields from kwargs
            for field_name, field_value in kwargs.items():
                logger.info(f"field_name:{field_name},field_value:{field_value}")
                if field_value is not None:
                    setattr(test, field_name, field_value)
            test.save()
        except Exception as e:
            logger.error(f"Error while storing message data: {e}")
