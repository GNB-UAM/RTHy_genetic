from scipy.signal import butter, lfilter, filtfilt, freqz

def butter_filter(data, cutoff_freq, sampling_rate, order=5, type='high'):

	# Get filter coefficients to check the frequency response
    nyq = 0.5 * sampling_rate
    normal_cutoff = cutoff_freq / nyq
    b, a = butter(order, normal_cutoff, btype=type, analog=False)

    # Apply the filter
    return filtfilt(b, a, data)

def threshold_filter(data, threshold, remove='above'):
	if remove=='above':
		for i in range(len(data)):
			if data[i] < threshold:
				data[i] = threshold
		return

	if remove=='over':
		for i in range(len(data)):
			if data[i]>threshold:
				data[i] = threshold
		return
