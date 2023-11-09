from .models import TestData
import logging
logger = logging.getLogger(__name__)

class DBManager:
    def store_test_data(self, message_uiid, **kwargs):
        logger.info("Store Message Data")
        try:
            test, _ = TestData.objects.get_or_create(message_uiid=message_uiid)
            # Update fields from kwargs
            for field_name, field_value in kwargs.items():
                if field_value is not None:
                    setattr(test, field_name, field_value)
            test.save()
        except Exception as e:
            logger.error(f"Error while storing message data: {e}")
