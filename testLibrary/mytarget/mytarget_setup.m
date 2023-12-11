function mytarget_setup()
    curpath = pwd;
    tgtpath = curpath(1:end-length('\mytarget'));
    addpath(fullfile(tgtpath,'mytarget'));
    addpath(fullfile(tgtpath,'tool'));
    addpath(fullfile(tgtpath,'blocks'));
    addpath(fullfile(tgtpath,'doc'));
    savepath;
    disp('MYTARGET TARGET PATH SETUP COMPLETE');