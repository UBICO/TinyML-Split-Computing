import logging
logger = logging.getLogger(__name__)

class OffloadingManager:
    def __init__(self, avg_speed, num_layers, layers_sizes, inference_time_device, inference_time_edge) -> None:
        self.avg_speed = avg_speed
        self.num_layers = num_layers
        self.layers_sizes = layers_sizes
        self.inference_time_device = inference_time_device
        self.inference_time_edge = inference_time_edge
        self.best_layer = 0
        self.lowest_evaluation = float('inf')
        self.layer_zero_data_size = self.layers_sizes[0]

    def evaluation(self, initial_cost, layer_data_size, edge_computation_costs, avg_speed):
        logger.info("---------------------------------")
        logger.info(f"DS:           {layer_data_size}")
        logger.info(f"IC:           {initial_cost}")
        logger.info(f"CE:           {edge_computation_costs}")
        logger.info(f"AvgSpeed:     {avg_speed}")
        evaluation = round( initial_cost + (layer_data_size/avg_speed ) + edge_computation_costs, 3)
        logger.info(f"Evaluation =  {evaluation}")
        return evaluation

    def static_offloading_evaluation(self):
        logger.info(f"Total Neural Network Layer: {self.num_layers}")

        # Fast offloading - Edge Only Computation
        self.lowest_evaluation = self.evaluation(
            initial_cost=0,
            layer_data_size=self.layers_sizes[0],
            avg_speed=round(self.avg_speed,3),
            edge_computation_costs=sum(self.inference_time_edge[:self.num_layers+1]),
        )

        # Partial Offloading - Edge and Device Computation 
        for layer in range(0, self.num_layers): 
            evaluation = self.evaluation(
                initial_cost=(0 if layer==0 else sum(self.inference_time_device[:layer])),
                layer_data_size=self.layers_sizes[layer+1],
                avg_speed=round(self.avg_speed,3),
                edge_computation_costs=sum(self.inference_time_edge[layer:self.num_layers]) ,
            )
            if evaluation < self.lowest_evaluation:
                self.best_layer = layer 
                self.lowest_evaluation = evaluation

        # No Offloading - Device Computation Only
        last_evaluation = self.evaluation = self.evaluation(
            initial_cost = sum(self.inference_time_device[:self.num_layers+1]),
            layer_data_size=0,
            avg_speed=round(self.avg_speed,3),
            edge_computation_costs=0,
        )
        if last_evaluation < self.lowest_evaluation:
            self.best_layer = self.num_layers
            self.lowest_evaluation = last_evaluation

        logger.info(f"Offloading from: {self.best_layer} layer - {self.lowest_evaluation}")

        return self.best_layer, self.lowest_evaluation, self.layers_sizes[self.best_layer], self.layer_zero_data_size