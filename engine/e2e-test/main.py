import pytest
from test_api_engine_list import TestApiEngineList
from test_cli_engine_get import TestCliEngineGet
from test_cli_engine_install import TestCliEngineInstall
from test_cli_engine_list import TestCliEngineList
from test_cli_engine_uninstall import TestCliEngineUninstall
from test_cortex_update import TestCortexUpdate
from test_cli_server_start import TestCliServerStart
from test_create_log_folder import TestCreateLogFolder

if __name__ == "__main__":
    pytest.main([__file__, "-v"])
