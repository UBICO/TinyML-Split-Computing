from django.urls import path
from .views import test, full_nn_predict

urlpatterns = [
    path('nn-model/test/<str:nn_id>', test, name='test'),
    path('nn-model/full_nn_predict/', full_nn_predict, name='full_nn_predict'),
]
