#include "FiducialCut_DC_ThetaPhi.h"
#include <TDatabasePDG.h>

namespace chanser{
  
  void FiducialCut_DC_ThetaPhi::ChangeRun()
  {
    if(GetCLAS12()==nullptr) return;
    _fieldVal =  GetCLAS12()->runconfig()->getTorus();
     bool inbending = (_fieldVal==-1);
     //these should come from database
     //For now copy appropriate values
     _minparams = (inbending ? _minparams_in : _minparams_out);
     _maxparams = (inbending ? _maxparams_in : _maxparams_out);
  }
  FiducialCut_DC_ThetaPhi::FiducialCut_DC_ThetaPhi(TString pid,Int_t layer)
  {

    auto pdg=TDatabasePDG::Instance()->GetParticle(pid)->PdgCode();
    if(pdg == 11) _partPidVal=0;
    else if (pdg==2212) _partPidVal=1;
    else if (pdg==211) _partPidVal= 2;
    else if (pdg==-211) _partPidVal = 3;
    else if (pdg==321) _partPidVal=4;
    else if (pdg==-321) _partPidVal=5;
    else{
      std::cerr<<"FiducialCut_DC_ThetaPhi, invalid layer PID "<<pid<<" "<<pdg<<std::endl;
      exit(0);
    }
    
    if(layer==1){
      _regionVal=6;
      _layer = layer-1;
    }
    else if(layer==2){
      _regionVal=18;
      _layer=layer-1;
    }
    else if(layer==3){
      _regionVal=36;
     _layer=layer-1;
    }
    else{
      std::cerr<<"FiducialCut_DC_ThetaPhi, invalid layer should be 1,2,3 "<<std::endl;
      exit(0);
    }
   

    
    _maxparams_in = {
      {{{-51.2054, 38.3199, -2.34912, 0.0195708},{-35.124, 26.5405, -1.09976, 0.0054436},{-38.4667, 28.8007, -1.29647, 0.00723946}},
       {{-37.5758, 26.6792, -1.00373, 0.00425542},{-45.5585, 35.2513, -2.21029, 0.0196454},{-40.6878, 30.355, -1.42152, 0.00817034}},
       {{-38.3878, 29.6034, -1.68592, 0.0150766},{-36.8921, 27.4735, -1.14582, 0.00554924},{-23.5149, 18.0147, -0.38597, 2.87092e-09}},
       {{-48.2748, 35.4465, -1.92023, 0.0136412},{-32.9275, 24.1143, -0.715458, 5.40587e-05},{-62.2819, 53.7417, -5.16183, 0.0613377}},
       {{-39.9916, 30.4254, -1.72002, 0.015037},{-20.4886, 16.3741, -0.310525, 2.68397e-08},{-38.2334, 31.4077, -2.12755, 0.021869}},
       {{-62.9673, 48.747, -3.71315, 0.036982},{-50.8588, 37.2435, -1.98066, 0.0126239},{-72.3186, 58.7791, -5.21921, 0.0573224}}},
      {{{-7.47342e-07, 12.8291, -0.819744, 0.00818184},{-3.46906, 12.9438, -0.594252, 0.00438008},{-6.57983, 11.8439, -0.240227, 3.27439e-10}},
       {{-2.23025e-08, 12.8274, -0.819395, 0.00817682},{-4.95047, 13.5494, -0.600411, 0.00406046},{-8.411, 12.7605, -0.278882, 2.14459e-10}},
       {{-3.62667e-08, 13.2965, -0.904711, 0.00919042},{-9.89194, 16.9776, -0.934777, 0.00761783},{-5.88727, 11.4158, -0.218181, 5.04197e-11}},
       {{-1.51214e-08, 12.7606, -0.797213, 0.00785312},{-5.63162, 14.3101, -0.702664, 0.00528812},{-4.77062, 10.9184, -0.200027, 2.67841e-13}},
       {{-1.81438e-08, 12.9692, -0.848261, 0.00859668},{-8.30238, 16.2372, -0.899398, 0.00745394},{-7.58827, 12.4473, -0.270602, 2.53855e-10}},
       {{-4.29779e-08, 13.121, -0.861715, 0.0085118},{-7.36773, 15.334, -0.776242, 0.00585805},{-6.54892, 12.0405, -0.259209, 3.73643e-06}}},
      {{{-2.68279e-07, 12.99, -0.846226, 0.00845788},{-14.6317, 19.3874, -1.09244, 0.00899541},{-38.1915, 29.8688, -1.59229, 0.0120089}},
       {{-0.996514, 13.9379, -0.964686, 0.00982941},{-15.9613, 20.2461, -1.16106, 0.00955431},{-35.9455, 29.0996, -1.586, 0.0122175}},
       {{-1.14284e-07, 13.6015, -0.966952, 0.0101523},{-15.5288, 20.3045, -1.20523, 0.0102808},{-34.2682, 26.4216, -1.20609, 0.0078434}},
       {{-1.70075e-08, 13.0005, -0.832325, 0.00817159},{-7.66776, 15.4526, -0.779727, 0.00585967},{-26.8035, 23.9995, -1.2322, 0.00942061}},
       {{-9.53804e-10, 13.2563, -0.898206, 0.00917629},{-6.85083, 14.8485, -0.722803, 0.0053221},{-39.3606, 31.5412, -1.83015, 0.0148302}},
       {{-7.66835e-07, 13.937, -1.05153, 0.0118223},{-9.7913, 16.925, -0.913158, 0.00712552},{-27.722, 23.9412, -1.1314, 0.00761088}}},
      {{{-22.1832, 20.4134, -0.764848, 0.00310923},{-31.0844, 28.2369, -1.715, 0.0145145},{-9.52175, 18.7932, -1.38896, 0.0150233}},
       {{-21.5849, 20.2457, -0.762109, 0.00305359},{-19.5601, 21.5945, -1.18955, 0.00939109},{-1.57084, 13.3989, -0.823161, 0.00795227}},
       {{-16.052, 16.6264, -0.444308, 2.82701e-06},{-13.8291, 18.6541, -1.01549, 0.00825776},{-1.92223e-05, 13.0305, -0.881089, 0.00925281}},
       {{-19.821, 18.4301, -0.516168, 2.17199e-10},{-30.6295, 28.0989, -1.71897, 0.0146585},{-9.23709, 17.1589, -1.03955, 0.00943673}},
       {{-16.1795, 16.7121, -0.448883, 1.53774e-11},{-23.6418, 24.5748, -1.48652, 0.01254},{-4.2626e-09, 12.899, -0.845374, 0.00872171}},
       {{-9.74791, 15.0287, -0.531727, 0.00192371},{-41.0848, 33.1802, -1.97671, 0.0158148},{-4.12428, 14.3361, -0.820483, 0.00725632}}},
      {{{-106.938, 86.1515, -8.33159, 0.101803},{-147.879, 123.116, -13.5824, 0.189579},{-40.461, 32.3475, -1.89454, 0.0152611}},
       {{-116.247, 96.2163, -9.93814, 0.130211},{-148.54, 117.766, -12.0624, 0.156313},{-21.2546, 20.4237, -0.895905, 0.00581147}},
       {{-1.80778e-07, 13.0131, -0.835058, 0.00806212},{-142.768, 110.58, -10.8081, 0.133187},{-68.8917, 52.0911, -3.89921, 0.0389652}},
       {{-120.479, 92.6075, -8.56746, 0.0999391},{-147.549, 115.807, -11.6707, 0.149171},{-68.1786, 52.4364, -4.06328, 0.042723}},
       {{-123.541, 97.8256, -9.57399, 0.118002},{-149.955, 123.896, -13.5475, 0.187947},{-17.0127, 16.3323, -0.393286, 1.67366e-13}},
       {{-98.3311, 81.6497, -8.10227, 0.102672},{-149.833, 127.44, -14.5373, 0.209948},{-0.74045, 9.36883, -0.152603, 6.37437e-05}}},
      {{{-142.357, 114.799, -11.8528, 0.152895},{-149.875, 111.604, -10.4642, 0.125095},{-149.501, 121.578, -13.0379, 0.177271}},
       {{-29.9249, 22.0873, -0.60085, 1.3473e-10},{-42.0584, 33.3444, -1.99565, 0.016557},{-150, 127.502, -14.6523, 0.21559}},
       {{-118.755, 95.587, -9.52135, 0.120561},{-144.344, 109.666, -10.4534, 0.126138},{-149.437, 93.2368, -6.50292, 0.0579289}},
       {{-149.814, 110.828, -10.2785, 0.122489},{-148.167, 114.308, -11.2695, 0.140999},{-149.539, 112.153, -10.6506, 0.128573}},
       {{-33.521, 26.8939, -1.29466, 0.00851674},{-141.738, 107.08, -10.1005, 0.120796},{-150, 108.507, -9.8741, 0.116558}},
       {{-26.8311, 20.6856, -0.549123, 5.34572e-11},{-148.673, 110.129, -10.1547, 0.118973},{-120.868, 101.527, -10.6726, 0.13942}}}};

    _minparams_in = {
      {{{38.6069, -28.188, 1.18288, -0.00589988},{26.3209, -21.6986, 0.768368, -0.00281998},{15.8707, -11.8368, 3.22688e-09, -8.36654e-10}},
       {{44.6032, -32.8751, 1.65153, -0.0105575},{51.7598, -35.5217, 1.29448, -2.11513e-06},{32.9204, -26.2522, 1.46865, -0.0139537},},
       {{32.1412, -24.2383, 1.00154, -0.0064333},{31.3784, -23.4733, 0.774187, -0.00203468},{53.8936, -44.9217, 3.8766, -0.0442173}},
       {{43.416, -32.3319, 1.78081, -0.0143004},{50.0314, -38.5805, 2.56055, -0.0235214},{25.8309, -21.3241, 1.01076, -0.00944255}},
       {{50.4741, -40.1723, 3.0563, -0.0325218},{61.6178, -50.3165, 4.34833, -0.0483999},{12.7766, -11.4712, 0.0511044, -1.74577e-10}},
       {{43.2153, -31.5115, 1.4834, -0.00863028},{69.3381, -51.2282, 3.39516, -0.0272937},{120.36, -85.4755, 7.45064, -0.0836405}}},
      {{{0.923008, -13.7147, 0.895123, -0.00853805},{7.6279, -15.4483, 0.798758, -0.00633026},{5.62644, -11.4345, 0.226312, -1.25172e-09}},
       {{2.50458, -14.7412, 1.01929, -0.0102917},{9.0023, -16.3615, 0.894467, -0.00751183},{3.69192, -10.4985, 0.188359, -3.1185e-10}},
       {{1.5978, -13.7835, 0.890884, -0.00868481},{13.4977, -19.2788, 1.15784, -0.0101226},{3.82792, -10.4417, 0.179639, -2.24507e-10}},
       {{1.97078e-05, -13.0168, 0.817426, -0.00762709},{6.07517, -14.4662, 0.696387, -0.00504973},{6.98517, -12.2129, 0.264062, -2.7665e-11}},
       {{2.39018e-09, -13.0476, 0.838641, -0.00809971},{4.15408, -14.0986, 0.777823, -0.00678748},{3.77333, -10.6691, 0.201849, -4.83515e-10}},
       {{0.00103141, -13.1638, 0.857402, -0.00828706},{7.16766, -15.2964, 0.811382, -0.00673444},{3.39768, -10.2477, 0.172417, -3.86335e-10}}},
      {{{1.59369e-06, -13.8294, 0.990918, -0.0103128},{20.1273, -23.853, 1.58449, -0.0145959},{40.8152, -32.8944, 2.00731, -0.0171007}},
       {{1.4334, -14.5452, 1.04379, -0.0106791},{19.9242, -23.3894, 1.5036, -0.0134429},{45.1348, -34.9897, 2.11238, -0.0175613}},
       {{4.48276e-06, -12.6688, 0.757818, -0.006981},{10.2525, -16.9056, 0.909637, -0.00739798},{33.2958, -27.7763, 1.53467, -0.0123488}},
       {{3.817e-06, -13.2285, 0.856439, -0.0081744},{12.5356, -19.0801, 1.1686, -0.0102758},{37.3388, -29.7344, 1.64296, -0.0130658}},
       {{3.64842e-07, -14.1631, 1.0771, -0.0118569},{9.85442, -17.8198, 1.12641, -0.010627},{34.7, -28.5335, 1.57226, -0.0124004}},
       {{0.828721, -13.6429, 0.895665, -0.00866683},{10.8176, -18.0919, 1.11147, -0.010183},{29.9288, -24.3389, 1.08973, -0.00703934}}},
      {{{15.8302, -16.9632, 0.53561, -0.00136216},{32.8002, -29.2569, 1.79783, -0.015324},{1.98393, -13.0099, 0.70788, -0.00615153}},
       {{16.0367, -16.5901, 0.470678, -0.000728065},{32.4005, -29.7403, 1.92286, -0.0171968},{2.39707, -13.6612, 0.816883, -0.00770837}},
       {{22.0623, -21.6319, 1.02811, -0.00680893},{32.7467, -29.6099, 1.87839, -0.0164223},{1.19902e-08, -12.972, 0.863127, -0.00884759}},
       {{21.5883, -21.198, 0.957819, -0.00575361},{25.7387, -25.4963, 1.5428, -0.0131855},{6.06479, -16.6311, 1.16092, -0.0117194}},
       {{19.6915, -19.1751, 0.704086, -0.00288768},{28.6596, -27.3351, 1.70309, -0.0148193},{5.30096e-08, -11.8562, 0.621373, -0.00541869}},
       {{20.6594, -19.8704, 0.786033, -0.00394155},{20.7612, -22.3774, 1.27116, -0.0104109},{2.56196, -14.4159, 0.98009, -0.0100214}}},
      {{{14.2631, -23.4009, 1.97498, -0.0231565},{4.79173, -12.3009, 0.326886, -1.01998e-11},{116.734, -88.2089, 8.05103, -0.0957363}},
       {{5.23149, -16.0375, 1.0661, -0.0101511},{110.165, -85.9607, 7.97299, -0.0942078},{43.5095, -33.7305, 1.93256, -0.0149425}},
       {{1.85579e-09, -11.9228, 0.619166, -0.00523146},{7.01255, -15.5132, 0.84916, -0.00706963},{149.945, -108.603, 9.82162, -0.114667}},
       {{140.48, -115.163, 12.1689, -0.16217},{133.49, -104.362, 10.1931, -0.125813},{114.099, -83.4723, 7.13202, -0.0793527}},
       {{18.6833, -24.9619, 1.82946, -0.0167602},{11.0804, -17.1484, 0.877833, -0.00652953},{15.5084, -15.7594, 0.378209, -2.63283e-06}},
       {{4.64372e-08, -8.1395, 0.0139504, -9.40293e-06},{74.1514, -64.5468, 6.22895, -0.0765922},{29.0616, -24.2817, 1.13928, -0.00789879}}},
      {{{150, -119.236, 12.4315, -0.16672},{17.764, -15.9517, 0.338355, -9.39693e-11},{149.387, -101.062, 8.19036, -0.0851116}},
       {{130.018, -97.9952, 9.09323, -0.109458},{147.831, -109.347, 10.1054, -0.119381},{149.958, -109.621, 10.0894, -0.119333}},
       {{149.744, -119.521, 12.5308, -0.168366},{105.835, -82.9887, 7.74468, -0.0929233},{135.964, -117.822, 13.5665, -0.197518}},
       {{150, -119.218, 12.431, -0.167282},{43.2244, -35.0239, 2.19659, -0.0185046},{150, -115.904, 11.6807, -0.151716}},
       {{149.062, -108.704, 9.81712, -0.113862},{144.909, -115.147, 11.8228, -0.153516},{150, -115.103, 11.5315, -0.149515}},
       {{149.245, -111.727, 10.5343, -0.126258},{127.9, -98.607, 9.4799, -0.117458},{135.306, -106.942, 10.7421, -0.136543}}}};

    _maxparams_out = {
      {{{-3.69457, 12.3755, -0.41328, 0.00129631},{-54.3237, 40.3308, -2.39952, 0.0181339},{-39.8661, 27.1428, -0.907303, 0.00220974}},
       {{-37.6199, 26.2865, -0.826366, 0.000862203},{-72.4212, 54.7953, -4.04856, 0.0373308},{-21.1791, 17.0759, -0.391795, 0.00151085}},
       {{-0.421685, 10.482, -0.272111, 8.69408e-05},{-43.3635, 32.746, -1.6541, 0.0101454},{-62.6387, 41.1869, -1.97298, 0.0107022}},
       {{-42.0766, 29.6387, -0.993426, 1.97101e-09},{-44.7036, 33.0587, -1.64131, 0.0099416},{-47.2703, 32.6109, -1.46533, 0.00817871}},
       {{-22.2035, 20.6894, -0.689051, 0.000592423},{-74.6572, 54.7065, -3.83999, 0.0351952},{-38.9183, 25.7212, -0.711499, 2.5796e-12}},
       {{-52.078, 45.571, -3.71942, 0.0376577},{-65.4047, 49.1723, -3.36623, 0.0288435},{-53.9611, 35.9294, -1.58589, 0.00772417}}},
      {{{-2.20312e-07, 13.0916, -0.864184, 0.0086342},{-6.44026e-08, 12.056, -0.675801, 0.00643464},{-20.2596, 23.5977, -1.545, 0.0141047}},
       {{-4.42537e-05, 10.2799, -0.322454, 0.00154825},{-1.63659e-07, 11.0228, -0.451412, 0.00308633},{-8.5382, 15.6903, -0.785315, 0.00602734}},
       {{-2.32088, 11.6343, -0.363509, 0.000902217},{-0.301128, 12.0319, -0.643794, 0.00581994},{-22.4378, 25.2772, -1.73656, 0.0164181}},
       {{-7.40627, 13.601, -0.382439, 2.45262e-05},{-5.50415e-08, 11.9792, -0.652368, 0.00597647},{-15.1608, 20.6455, -1.33827, 0.0127123}},
       {{-0.203913, 10.7032, -0.322123, 0.000691162},{-1.73184e-07, 10.735, -0.379993, 0.00196037},{-0.155443, 10.1794, -0.249841, 6.24278e-05}},
       {{-1.87352e-07, 12.4226, -0.730141, 0.0068049},{-1.40236e-07, 12.5356, -0.750615, 0.00719921},{-16.8681, 21.8555, -1.43078, 0.0131935}}},
      {{{-8.89326e-08, 10.0681, -0.240869, 9.9612e-12},{-15.2705, 21.635, -1.55291, 0.0166645},{-10.5976, 17.9928, -1.08432, 0.00950807}},
       {{-0.00389562, 10.2092, -0.254082, 4.15737e-06},{-9.16032e-11, 10.527, -0.334641, 0.00129061},{-9.63013e-07, 11.0668, -0.42453, 0.0022955}},
       {{-2.40163e-06, 13.4151, -0.949883, 0.0107662},{-1.60937e-07, 10.5128, -0.35046, 0.00173787},{-29.2647, 30.1252, -2.20552, 0.0213809}},
       {{-2.69733e-08, 11.7703, -0.589854, 0.00482124},{-3.77564e-08, 11.3764, -0.527037, 0.00416671},{-4.85047, 13.7737, -0.650441, 0.0047428}},
       {{-3.90816e-07, 12.2683, -0.692591, 0.00625884},{-9.70203e-10, 11.0335, -0.438323, 0.00275342},{-2.54193, 13.5404, -0.76861, 0.00684486}},
       {{-3.23439e-10, 10.7412, -0.348557, 0.00113794},{-1.79623, 11.7499, -0.449432, 0.00247294},{-13.1393, 19.4689, -1.17148, 0.00984086}}},
      {{{-5.07611e-08, 11.7796, -0.516966, 0.00295389},{-4.87018, 12.2727, -0.322719, 9.12315e-06},{-35.9369, 31.015, -1.95133, 0.0169834}},
       {{-1.32385e-07, 11.6454, -0.495467, 0.00272602},{-2.70664, 12.0151, -0.434014, 0.00203292},{-8.97137, 15.0453, -0.646138, 0.00429196}},
       {{-7.92247e-09, 12.5189, -0.682231, 0.00539531},{-0.0942499, 10.3465, -0.280521, 0.000405358},{-19.7485, 21.7919, -1.24334, 0.0105088}},
       {{-8.50093e-11, 10.739, -0.302295, 5.6862e-11},{-0.184771, 10.4358, -0.285869, 0.000389546},{-21.9469, 24.9675, -1.77893, 0.0183075}},
       {{-4.34589, 12.5902, -0.362849, 4.996e-15},{-0.000684493, 10.6055, -0.332363, 0.00104632},{-21.328, 22.0864, -1.20993, 0.00989151}},
       {{-0.0202168, 12.0097, -0.539165, 0.00299034},{-0.5239, 10.7167, -0.309141, 0.000535617},{-10.0299, 16.3179, -0.812315, 0.00617078}}},
      {{{-0.169908, 10.902, -0.353938, 0.00100715},{-3.2818, 13.2193, -0.65495, 0.00515117},{-0.013532, 8.51331, -0.070239, 1.755e-05}},
       {{-8.51985e-08, 11.6512, -0.56808, 0.00453582},{-1.2381e-07, 10.6653, -0.368149, 0.00181989},{-9.30287e-08, 10.0352, -0.254321, 0.000417053}},
       {{-0.150407, 10.6338, -0.308676, 0.000481694},{-0.00186321, 10.4259, -0.303092, 0.00073092},{-21.3328, 28.0803, -2.37912, 0.025101}},
       {{-14.4411, 19.817, -1.13705, 0.00894685},{-6.25263e-09, 11.7414, -0.586098, 0.00478932},{-5.49193, 16.1248, -1.11306, 0.0115644}},
       {{-1.54761, 12.0015, -0.462506, 0.00204729},{-5.72883, 14.9638, -0.795325, 0.00616222},{-50.229, 45.8456, -3.88803, 0.0414729}},
       {{-40.7531, 33.6269, -2.03771, 0.01609},{-1.33363e-09, 11.9894, -0.614358, 0.004924},{-27.2506, 29.2602, -2.1426, 0.0203235}}},
      {{{-1.62999e-10, 14.0422, -1.03609, 0.0107179},{-6.71565, 15.6964, -0.887791, 0.00740777},{-38.9148, 32.9935, -2.09023, 0.0177295}},
       {{-1.09078e-05, 13.4131, -0.878092, 0.00825152},{-15.0102, 21.6968, -1.4935, 0.0138851},{-19.5261, 20.3932, -0.969464, 0.00661531}},
       {{-1.39619e-08, 12.3593, -0.618488, 0.00415536},{-5.38271e-07, 11.5631, -0.512607, 0.00334452},{-23.0902, 24.7093, -1.57315, 0.0140132}},
       {{-1.73908e-08, 12.0348, -0.591608, 0.00423834},{-8.35134, 17.3066, -1.11555, 0.010407},{-2.74909e-07, 9.59202, -0.216455, 0.000527479}},
       {{-0.0449157, 10.5243, -0.334389, 0.00134555},{-0.0143489, 10.0993, -0.2434, 1.57595e-10},{-22.3661, 23.2499, -1.32946, 0.0108047}},
       {{-5.83731e-07, 14.5234, -1.14022, 0.0122177},{-1.4586e-08, 11.6946, -0.520935, 0.00324975},{-12.4252, 16.3216, -0.652566, 0.00365791}}}};

    _minparams_out  = {
      {{{3.73672, -12.3584,0.390616, -0.000795415},{51.644, -37.8546,1.99228, -0.0119973},{32.3551, -22.9742,0.624096, -4.30811e-05}},
       {{6.11614, -13.6358,0.491668, -0.0018637},{47.5098, -35.902,1.97535, -0.0134876},{82.9536, -58.2741,4.12662, -0.0378612}},
       {{0.000950108, -7.99619,0.000506416, -0.0020788},{64.0688, -47.8642,3.16007, -0.025878},{70.0064, -50.3249,3.38975, -0.029639}},
       {{37.0145, -35.0316,2.61892, -0.0250306},{14.5954, -15.6554,0.426733, -0.000879865},{28.9035, -21.5279,0.610475, -0.00087271}},
       {{5.65685, -13.3347,0.400781, -1.46612e-11},{67.3504, -50.152,3.33677, -0.0270726},{47.0772, -32.1506,1.38851, -0.00719898}},
       {{8.95987, -15.1646,0.585477, -0.00246174},{41.6154, -29.7967,1.1817, -0.00403765},{61.1631, -41.6465,2.32522, -0.0175271}}},
      {{{8.80954e-10, -11.0364,0.413853, -0.00210254},{6.50072e-08, -11.2505,0.501571, -0.00380973},{10.9643, -17.4701,0.989297, -0.00860789}},
       {{2.33292e-08, -11.2353,0.470728, -0.00309666},{2.29373e-07, -11.2458,0.50218, -0.00383969},{29.5429, -29.9965,2.19166, -0.021366}},
       {{1.61826e-08, -11.861,0.577321, -0.00433276},{2.9436e-07, -11.5738,0.581015, -0.00503307},{19.5142, -23.451,1.58724, -0.0151339}},
       {{2.07231e-09, -12.7453,0.751184, -0.00664181},{1.77802e-07, -11.4574,0.537367, -0.00422656},{12.5683, -18.4632,1.05475, -0.00892182}},
       {{7.6216e-08, -13.9769,1.01051, -0.0107372},{1.33092e-08, -11.9128,0.628521, -0.00550105},{13.5537, -20.1708,1.32578, -0.0123213}},
       {{9.25941, -19.658,1.51566, -0.0157124},{6.25983e-10, -11.6806,0.599263, -0.00532588},{17.0479, -22.0046,1.47474, -0.0140475}}},
      {{{4.65436e-08, -11.1925,0.466196, -0.00308992},{18.4968, -22.5122,1.4594, -0.0135962},{18.9488, -23.3348,1.57414, -0.0146183}},
       {{3.67722e-08, -10.9985,0.428395, -0.00257574},{16.3745, -21.0105,1.3093, -0.0119156},{11.4404, -18.6679,1.15919, -0.010306}},
       {{1.46846e-08, -10.865,0.398638, -0.00212392},{20.7337, -23.3738,1.46852, -0.0130115},{28.2098, -28.9406,2.05908, -0.0197782}},
       {{0.237058, -10.4694,0.271985, -1.08731e-07},{2.32759, -11.9354,0.469887, -0.00291497},{13.287, -20.8621,1.49656, -0.0148999}},
       {{0.000149907, -10.4632,0.294713, -0.000431947},{6.96663, -15.3946,0.845078, -0.00724722},{11.0939, -17.4733,0.944239, -0.00747728}},
       {{3.10006e-08, -10.1416,0.247764, -1.36913e-11},{5.41915, -14.6085,0.795369, -0.00684375},{5.89127, -13.0881,0.453024, -0.0020325}}},
      {{{4.16588e-09, -12.9305,0.749425, -0.00611725},{5.65263, -14.1661,0.637395, -0.00400239},{4.66325, -12.9519,0.565753, -0.00442033}},
       {{8.0428e-08, -13.1625,0.836744, -0.00778246},{12.3243, -18.8718,1.11103, -0.00917354},{7.20312, -16.0935,0.987223, -0.00930883}},
       {{0.00147165, -10.4992,0.280542, -1.79846e-06},{3.20232, -11.6892,0.350774, -0.00101099},{8.14117e-08, -10.9813,0.524839, -0.00507885}},
       {{0.470888, -13.5446,0.820782, -0.00768941},{3.9697, -13.0821,0.540847, -0.00303209},{3.44817, -12.3932,0.533804, -0.00414144}},
       {{1.05038e-08, -10.6539,0.297078, -6.04694e-05},{15.0983, -21.1791,1.38383, -0.0124058},{17.3666, -20.3986,1.16663, -0.0102393}},
       {{8.49365e-07, -13.765,0.964056, -0.00956575},{9.38084, -16.7385,0.904339, -0.00707907},{12.1048, -17.3704,0.91318, -0.00757461}}},
      {{{10.6378, -19.5017,1.45275, -0.017057},{1.24368e-08, -10.5134,0.338985, -0.00143696},{37.3291, -35.1606,2.60092, -0.0242728}},
       {{19.1614, -24.0851,1.73932, -0.0185466},{14.1293, -19.8382,1.21613, -0.0107037},{20.9629, -24.0839,1.60283, -0.015173}},
       {{0.000450804, -8.15062,0.0103867, -2.00709e-05},{5.72496, -14.338,0.717819, -0.00567964},{16.9428, -21.8075,1.4216, -0.0131736}},
       {{6.15991e-10, -11.5278,0.536105, -0.00402223},{2.17842e-07, -10.5338,0.327427, -0.0010898},{20.7387, -24.3028,1.65004, -0.0155857}},
       {{0.650351, -10.6177,0.275393, -6.4664e-08},{8.05811, -16.1558,0.913735, -0.00788487},{0.308897, -10.2816,0.275186, -0.000561299}},
       {{0.427836, -10.168,0.240458, -5.90042e-06},{2.30661, -12.8686,0.664796, -0.00562626},{0.00499667, -11.6585,0.62597, -0.00619261}}},
      {{{9.01249e-07, -11.8437,0.494125, -0.00223452},{14.3941, -21.2365,1.46048, -0.0137349},{13.7095, -15.4704,0.408961, -0.000312145}},
       {{0.000251044, -11.3084,0.438545, -0.0020791},{0.00847078, -12.6769,0.804431, -0.00836705},{1.09388, -9.66797,0.175278, -1.8721e-11}},
       {{4.04693e-10, -11.9001,0.585913, -0.00440376},{5.05178, -12.1514,0.31134, -0.000112735},{30.8105, -28.0795,1.73625, -0.0151639}},
       {{3.86607e-11, -13.471,0.889111, -0.0083617},{8.86591e-09, -9.25745,0.163052, -6.08491e-12},{27.1358, -24.3255,1.23326, -0.00891886}},
       {{0.196086, -11.7392,0.480055, -0.00224614},{0.18667, -10.5859,0.287231, -6.53153e-06},{14.8865, -17.1338,0.653576, -0.00333176}},
       {{2.7955e-07, -13.1311,0.848222, -0.00812719},{29.5508, -32.9514,2.77917, -0.0291596},{59.7514, -47.3033,3.54495, -0.0341802}}}};

  }
}
