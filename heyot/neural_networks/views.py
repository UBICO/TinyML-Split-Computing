from django.http import JsonResponse
import numpy as np
#from .nn_manager import perform_predict
import pandas as pd
from django.shortcuts import render

def test(request, nn_id):
    layer_outputs, total_predict_time, update_time = None, None, None #perform_predict(nn_id=nn_id, start_layer_index=0, data=np.random.rand(1,9))
    csv_file_path = f"./neural_networks/ai_models/{nn_id}/{nn_id}_analytics.csv" 
    analytics_data = pd.read_csv(csv_file_path)
    last_inference_time = analytics_data['Inference Time (s)'].to_list()
    result = {
        "total_predict_time(s)": str(total_predict_time),
        "layer_outputs" : layer_outputs,
        "update_time": update_time,
        "last_inference_time": str(last_inference_time),
    }
    return JsonResponse(result, safe=False)

def full_nn_predict(request):
    return render(request, 'heyot/neural_networks/full_nn_predict.html', {'notification': "notification"})
