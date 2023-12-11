from django.http import JsonResponse
import numpy as np
from .NNManager import NNManager
import pandas as pd
from django.shortcuts import render


def test(request, nn_id):
    start_layer_index = 0
    nn_manager = NNManager(nn_id=nn_id)
    fake_data = nn_manager.make_fake_data()
    layer_outputs, model_loading_time, update_time = nn_manager.perform_predict(start_layer_index=start_layer_index, data=fake_data)
    last_inference_time = nn_manager.get_model_analytics()["layer_inference_time"]
    result = {
        "total_predict_time(ms)": sum(last_inference_time.to_list()),
        "layer_outputs" : layer_outputs,
        "update_time": update_time,
        "last_inference_times(ms)": str(last_inference_time.to_list()),
    }
    return JsonResponse(result, safe=False)

def full_nn_predict(request):
    return render(request, 'heyot/neural_networks/full_nn_predict.html', {'notification': "notification"})
