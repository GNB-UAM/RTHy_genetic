#include "nm_izhikevich_2003.h"
#include "../../integration_methods.h"
#include "../neuron_models_aux_functions.h"

/**
 * @file nm_izhikevich_2003.h
 * @brief Source file for the Izhikevich_2003 model functions.
 */

/** @name Izhikevich_2003
 * Izhikevich_2003 neuron model.
 */
///@{

double nm_izhikevich_2003_v (double * vars, double * params);
double nm_izhikevich_2003_u (double * vars, double * params);
double nm_izhikevich_2003_set_pts_burst (double pts_live, neuron_model * nm);


double nm_izhikevich_2003_v (double * vars, double * params) {
	return 0.040000 * vars[NM_IZHIKEVICH_2003_V]*vars[NM_IZHIKEVICH_2003_V] + 5.000000 * vars[NM_IZHIKEVICH_2003_V] + 140.000000 - vars[NM_IZHIKEVICH_2003_U] + params[NM_IZHIKEVICH_2003_I] - params[NM_IZHIKEVICH_2003_SYN];
}

double nm_izhikevich_2003_u (double * vars, double * params) {
	return params[NM_IZHIKEVICH_2003_A] * (params[NM_IZHIKEVICH_2003_B] * vars[NM_IZHIKEVICH_2003_V] - vars[NM_IZHIKEVICH_2003_U]);
}

/**
 * @brief Izhikevich_2003 neuron model differential equations.
 * @param[in] vars Neuron model variables
 * @param[out] ret Return values array
 * @param[in] params Neuron models parameters
 * @param[in] syn Synapse input current value
 */

void nm_izhikevich_2003_f (double * vars, double * ret, double * params, double syn) {
	params[NM_IZHIKEVICH_2003_SYN] = syn;

	ret[NM_IZHIKEVICH_2003_V] = nm_izhikevich_2003_v(vars, params);
	ret[NM_IZHIKEVICH_2003_U] = nm_izhikevich_2003_u(vars, params);
}

/**
 * @brief Izhikevich_2003 neuron model.
 * @param[in] nm Neuron model structure
 * @param[in] syn Synapse input current value
 */

void nm_izhikevich_2003 (neuron_model nm, double syn) {
	nm.method(nm_izhikevich_2003_f, nm.dim, nm.params[NM_IZHIKEVICH_2003_DT], nm.vars, nm.params, syn);

	if (nm.vars[NM_IZHIKEVICH_2003_V] >= 30) {
        nm.vars[NM_IZHIKEVICH_2003_V] = nm.params[NM_IZHIKEVICH_2003_C];
        nm.vars[NM_IZHIKEVICH_2003_U] += nm.params[NM_IZHIKEVICH_2003_D];
    }

	return;
}

/**
 * @brief Initializes Izhikevich_2003 neuron model.
 * @param[in] nm Pointer to the neuron model structure
 * @param[in] vars Array with the initial values of the model variables
 * @param[in] params Array with the values of the mode parameters
 */

void nm_izhikevich_2003_init (neuron_model * nm, double * vars, double * params) {
	nm->dim = 2;
	nm->vars = (double *) malloc (sizeof(double) * nm->dim);
	copy_1d_array(vars, nm->vars, nm->dim);

	nm->n_params = 7;
	nm->params = (double *) malloc (sizeof(double) * nm->n_params);
	copy_1d_array(params, nm->params, nm->n_params);

	nm->max = 30.240470;
	nm->min = -74.235106;
	nm->pts_burst = -1.0;

	nm->func = &nm_izhikevich_2003;
	nm->set_pts_burst = &nm_izhikevich_2003_set_pts_burst;
	nm->method = integration_method_selector(params[NM_IZHIKEVICH_2003_DT]);

	return;
}

/**
 * @brief Sets Izhikevich_2003 model number of points per burst and integration step.
 * 
 * If not previously specified by the user, the number of points per burst of the model and its integration step is set according to the living neuron number of points per burst.
 * @param[in] pts_live Number of points in a living neuron burst
 * @param[in] nm Pointer to the neuron model structure
 */

double nm_izhikevich_2003_set_pts_burst (double pts_live, neuron_model * nm) {
	int length = 0;
	int method = nm->params[NM_IZHIKEVICH_2003_DT];

	switch(method) {
		case EULER:
		{
			length = 112.000000 - 58;
			double dts[] = {0.000010, 0.000200, 0.000300, 0.000400, 0.000500, 0.000600, 0.000700, 0.000800, 0.000900, 0.001000, 0.001100, 0.001200, 0.001300, 0.001400, 0.001500, 0.001600, 0.001700, 0.001800, 0.001900, 0.002000, 0.002100, 0.002200, 0.002300, 0.002400, 0.002600, 0.002800, 0.003000, 0.003200, 0.003400, 0.003700, 0.004000, 0.004400, 0.004800, 0.005300, 0.005900, 0.006000, 0.006100, 0.006200, 0.006300, 0.006400, 0.006500, 0.006600, 0.006700, 0.006800, 0.006900, 0.007000, 0.007100, 0.007200, 0.007300, 0.007400, 0.007500, 0.007600, 0.007800, 0.008000/*, 0.008200, 0.008400, 0.008600, 0.008800, 0.009000, 0.009200, 0.009400, 0.009600, 0.009800, 0.010000, 0.010200, 0.010400, 0.010600, 0.010800, 0.011100, 0.011400, 0.011700, 0.012000, 0.012300, 0.012600, 0.012900, 0.013200, 0.013600, 0.014000, 0.014400, 0.014800, 0.015200, 0.015600, 0.016100, 0.016600, 0.017100, 0.017700, 0.018300, 0.018900, 0.019600, 0.020300, 0.021100, 0.021900, 0.022800, 0.023800, 0.024900, 0.026100, 0.027300, 0.028700, 0.030200, 0.031800, 0.033700, 0.035800, 0.038200, 0.082200, 0.090300, 0.090500, 0.092200, 0.093500, 0.095200, 0.096700, 0.098400, 0.100000*/};
			double pts[] = {383277.000000, 296570.500000, 197716.750000, 148291.200000, 118634.714286, 98864.222222, 84742.200000, 74154.000000, 65913.928571, 59324.066667, 53933.000000, 49438.052632, 45637.350000, 42377.000000, 39554.000000, 37082.960000, 34900.333333, 32964.000000, 31231.000000, 29667.968750, 28256.617647, 26972.500000, 25801.000000, 24726.025641, 22823.047619, 21195.500000, 19780.020408, 18547.326923, 17457.000000, 16042.508197, 14838.000000, 13493.000000, 12368.987342, 11203.011364, 10065.500000, 9897.970000, 9733.980198, 9579.524272, 9427.009524, 9280.009434, 9138.000000, 8997.990909, 8864.495495, 8736.477876, 8607.669565, 8484.793103, 8367.500000, 8250.000000, 8138.231405, 8027.000000, 7920.336000, 7816.039683, 7618.284615, 7427.000000/*, 7245.985401, 7071.007143, 6910.972028, 6752.333333, 6603.993333, 6460.000000, 6323.000000, 6191.493750, 6063.503067, 5945.000000, 5826.500000, 5714.000000, 5606.502825, 5505.000000, 5356.000000, 5214.005263, 5080.000000, 4954.005000, 4835.000000, 4720.000000, 4611.000000, 4507.000000, 4374.000000, 4250.000000, 4130.995851, 4022.000000, 3916.988189, 3815.000000, 3696.000000, 3586.996390, 3478.996503, 3362.996622, 3252.598039, 3151.500000, 3040.498471, 2935.005900, 2822.008499, 2719.497268, 2612.005249, 2506.667506, 2395.992788, 2286.002294, 2184.002193, 2080.496868, 1977.329365, 1875.996241, 1771.996448, 1668.500000, 1564.004702, 1463.000000, 1337.000000, 666.967290, 656.500000, 645.985779, 635.967537, 625.252816, 615.012923, 605.001211*/};

			select_dt_neuron_model(dts, pts, length, pts_live, &(nm->params[NM_IZHIKEVICH_2003_DT]), &(nm->pts_burst));
			break;
		}
		case HEUN:
		{
			length = 100.000000 - 46;
			double dts[] = {0.000010, 0.000200, 0.000300, 0.000400, 0.000500, 0.000600, 0.000700, 0.000800, 0.000900, 0.001000, 0.001100, 0.001200, 0.001300, 0.001400, 0.001500, 0.001600, 0.001700, 0.001800, 0.001900, 0.002000, 0.002100, 0.002200, 0.002300, 0.002400, 0.002600, 0.002800, 0.003000, 0.003200, 0.003400, 0.003700, 0.004000, 0.004400, 0.004800, 0.005300, 0.005900, 0.006000, 0.006100, 0.006200, 0.006300, 0.006400, 0.006500, 0.006600, 0.006700, 0.006800, 0.006900, 0.007000, 0.007100, 0.007200, 0.007300, 0.007400, 0.007500, 0.007600, 0.007800, 0.008000/*, 0.008200, 0.008400, 0.008600, 0.008800, 0.009000, 0.009200, 0.009400, 0.009600, 0.009800, 0.010000, 0.010200, 0.010400, 0.010600, 0.010800, 0.011100, 0.011400, 0.011700, 0.012000, 0.012300, 0.012600, 0.012900, 0.013200, 0.013500, 0.013900, 0.014300, 0.014700, 0.015100, 0.015600, 0.016100, 0.016600, 0.017100, 0.017700, 0.018300, 0.018900, 0.019600, 0.020300, 0.021000, 0.021800, 0.022700, 0.023700, 0.024700, 0.077300, 0.092900, 0.097800, 0.098300, 0.100000*/};
			double pts[] = {383275.000000, 296562.000000, 197709.000000, 148282.800000, 118627.285714, 98856.666667, 84736.000000, 74144.333333, 65907.000000, 59317.933333, 53924.941176, 49430.421053, 45630.450000, 42371.000000, 39544.125000, 37075.160000, 34893.666667, 32954.172414, 31222.645161, 29662.000000, 28247.000000, 26965.555556, 25792.945946, 24715.974359, 22817.023810, 21187.608696, 19773.979592, 18540.519231, 17447.160714, 16033.983607, 14832.015152, 13483.000000, 12361.000000, 11195.000000, 10059.489796, 9888.000000, 9726.009901, 9572.495146, 9418.990476, 9274.000000, 9129.962963, 8992.000000, 8857.477477, 8726.000000, 8601.600000, 8478.336207, 8359.000000, 8240.000000, 8129.000000, 8017.065041, 7912.504000, 7810.000000, 7609.500000, 7419.015038/*, 7235.000000, 7064.992857, 6899.000000, 6743.496599, 6594.046667, 6449.668831, 6313.331210, 6182.500000, 6056.000000, 5936.988024, 5819.676471, 5708.011494, 5598.508475, 5495.494444, 5349.967568, 5208.005236, 5074.000000, 4946.000000, 4827.004854, 4709.672986, 4603.250000, 4499.000000, 4398.991150, 4273.000000, 4151.000000, 4039.000000, 3933.000000, 3807.988506, 3690.000000, 3579.000000, 3472.667832, 3357.000000, 3247.333333, 3142.000000, 3029.996960, 2929.000000, 2829.000000, 2728.000000, 2618.252632, 2509.000000, 2405.997585, 2299.205069, 1917.136276, 1167.479532, 608.749543, 598.512283*/};

			select_dt_neuron_model(dts, pts, length, pts_live, &(nm->params[NM_IZHIKEVICH_2003_DT]), &(nm->pts_burst));
			break;
		}
		case RK4:
		{
			length = 88.000000 - 33;
			double dts[] = {0.000010, 0.000200, 0.000300, 0.000400, 0.000500, 0.000600, 0.000700, 0.000800, 0.000900, 0.001000, 0.001100, 0.001200, 0.001300, 0.001400, 0.001500, 0.001600, 0.001700, 0.001800, 0.001900, 0.002000, 0.002100, 0.002200, 0.002300, 0.002400, 0.002600, 0.002800, 0.003000, 0.003200, 0.003400, 0.003700, 0.004000, 0.004400, 0.004800, 0.005300, 0.005900, 0.006000, 0.006100, 0.006200, 0.006300, 0.006400, 0.006500, 0.006600, 0.006700, 0.006800, 0.006900, 0.007000, 0.007100, 0.007200, 0.007300, 0.007400, 0.007500, 0.007600, 0.007700, 0.007900, 0.008100/*, 0.008300, 0.008500, 0.008700, 0.008900, 0.009100, 0.009300, 0.009500, 0.009700, 0.009900, 0.010100, 0.010300, 0.010500, 0.010700, 0.011000, 0.011300, 0.011600, 0.011900, 0.012200, 0.012500, 0.012800, 0.013100, 0.013400, 0.013800, 0.014200, 0.014600, 0.015000, 0.092600, 0.096900, 0.097000, 0.097200, 0.097400, 0.098400, 0.100000*/};
			double pts[] = {383275.000000, 296562.000000, 197709.000000, 148282.800000, 118627.285714, 98856.666667, 84736.000000, 74143.500000, 65907.071429, 59317.933333, 53924.941176, 49430.421053, 45630.350000, 42371.000000, 39544.625000, 37075.080000, 34893.666667, 32954.172414, 31222.645161, 29662.000000, 28247.000000, 26965.555556, 25792.945946, 24716.153846, 22817.023810, 21187.673913, 19773.979592, 18540.673077, 17447.125000, 16033.983607, 14832.015152, 13483.000000, 12361.000000, 11195.000000, 10059.500000, 9888.030000, 9726.009901, 9572.495146, 9418.990476, 9274.009434, 9129.962963, 8992.000000, 8857.477477, 8726.000000, 8601.669565, 8478.258621, 8359.000000, 8240.000000, 8129.000000, 8017.032520, 7912.504000, 7810.000000, 7709.000000, 7512.333333, 7330.000000/*, 7152.000000, 6983.000000, 6823.496552, 6668.000000, 6525.000000, 6381.503226, 6247.000000, 6119.012346, 5994.993939, 5878.011834, 5761.994186, 5654.005714, 5548.340782, 5396.994565, 5255.000000, 5119.005155, 4989.005025, 4866.000000, 4749.995215, 4639.000000, 4532.000000, 4431.169643, 4303.000000, 4181.491597, 4068.500000, 3958.657371, 3855.034749, 2044.610656, 1055.471459, 852.421862, 782.163665, 609.768010, 599.710684*/};

			select_dt_neuron_model(dts, pts, length, pts_live, &(nm->params[NM_IZHIKEVICH_2003_DT]), &(nm->pts_burst));
			break;
		}
		case RK65:
		{
			length = 83.000000 - 19;
			double dts[] = {0.000010, 0.000200, 0.000300, 0.000400, 0.000500, 0.000600, 0.000700, 0.000800, 0.000900, 0.001000, 0.001100, 0.001200, 0.001300, 0.001400, 0.001500, 0.001600, 0.001700, 0.001800, 0.001900, 0.002000, 0.002100, 0.002200, 0.002300, 0.002400, 0.002600, 0.002800, 0.003000, 0.003200, 0.003400, 0.003700, 0.004000, 0.004400, 0.004800, 0.005300, 0.005900, 0.006000, 0.006100, 0.006200, 0.006300, 0.006400, 0.006500, 0.006600, 0.006700, 0.006800, 0.006900, 0.007000, 0.007100, 0.007200, 0.007300, 0.007400, 0.007500, 0.007600, 0.007800, 0.008000, 0.008200, 0.008400, 0.008600, 0.008800, 0.009000, 0.009200, 0.009400, 0.009600, 0.009800, 0.010000/*, 0.010200, 0.010400, 0.010600, 0.010800, 0.011100, 0.011400, 0.011700, 0.012000, 0.012300, 0.012600, 0.012900, 0.092600, 0.096900, 0.097000, 0.097200, 0.097400, 0.097600, 0.098200, 0.100000*/};
			double pts[] = {383275.000000, 296562.000000, 197709.000000, 148282.800000, 118627.285714, 98856.666667, 84736.000000, 74143.500000, 65907.071429, 59317.933333, 53924.941176, 49430.421053, 45630.350000, 42371.000000, 39544.625000, 37075.080000, 34893.666667, 32954.172414, 31222.645161, 29662.000000, 28247.000000, 26965.555556, 25792.945946, 24716.153846, 22817.023810, 21187.673913, 19773.979592, 18540.673077, 17447.125000, 16033.983607, 14832.015152, 13483.000000, 12361.000000, 11195.000000, 10059.500000, 9888.030000, 9726.009901, 9572.495146, 9418.990476, 9274.009434, 9129.962963, 8992.000000, 8857.477477, 8726.000000, 8601.669565, 8478.258621, 8359.000000, 8240.000000, 8129.000000, 8017.032520, 7912.504000, 7810.000000, 7609.676923, 7419.015038, 7235.000000, 7064.992857, 6899.000000, 6743.496599, 6594.006667, 6450.480519, 6313.496815, 6183.000000, 6056.500000, 5936.982036/*, 5820.476471, 5708.011494, 5598.627119, 5495.500000, 5349.010811, 5208.005236, 5074.000000, 4946.000000, 4827.004854, 4709.758294, 4603.500000, 4497.207207, 2146.965591, 1043.224660, 842.464979, 783.403137, 674.209177, 610.585575, 599.731092*/};

			select_dt_neuron_model(dts, pts, length, pts_live, &(nm->params[NM_IZHIKEVICH_2003_DT]), &(nm->pts_burst));
			break;
		}
	}

	return nm->params[NM_IZHIKEVICH_2003_DT];
}

///@}