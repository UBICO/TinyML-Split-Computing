from django.db import models

class TestData(models.Model):
    message_uiid = models.CharField(primary_key=True, max_length=200)
    nn_id = models.CharField(max_length=255,blank=True, null=True)
    algo_id = models.CharField(max_length=255, blank=True, null=True)
    avg_speed = models.FloatField(blank=True, null=True)
    avg_latency = models.FloatField(blank=True, null=True)
    inference_dev = models.CharField(max_length=500, blank=True, null=True)
    inference_edge = models.CharField(max_length=500, blank=True, null=True)
    chosen_offloading_layer = models.CharField(max_length=255, blank=True, null=True)
    model_loading_time = models.FloatField(blank=True, null=True)
    update_time = models.FloatField(blank=True, null=True)
    synt_load_edge = models.FloatField(blank=True, null=True)
    synt_latency = models.FloatField(blank=True, null=True)
    offloaded_layer_data_size = models.FloatField(blank=True, null=True)
    layer_zero_data_size = models.FloatField(blank=True, null=True)
    def __str__(self):
        return f"Message ID: {self.message_uiid}"

