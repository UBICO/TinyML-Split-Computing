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

"""
db_manager = DBManager()
db_manager.store_test_data(
    message_uiid=message_uiid,
    layer_zero_data_size=layer_zero_data_size,
    offloaded_layer_data_size=offloaded_layer_data_size,
    synt_latency=synt_latency,
    synt_load_edge=synt_load_edge,
    avg_latency=avg_latency,
    avg_speed=avg_speed,
    nn_id=nn_id,
    algo_id=algo_id,
    inference_dev=inference_dev,
    inference_edge=inference_edge,
    chosen_offloading_layer=chosen_offloading_layer,
    model_loading_time=model_loading_time,
    update_time=update_time
)
"""