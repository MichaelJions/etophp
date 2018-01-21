<?php
switch ($argc) {
case 1:
	exit("PHP Create <Model/Controller/Project> <Name> <Path>\n");
	break;
case 2:
	exit("PHP Create <Model/Controller/Project> <Name> <Path>\n");
	break;
case 3:
	CreateDefault($argv);
	break;
case 4:
	CreatePathDefault($argv, $argv[3]);
	break;
}

function CreateDefault($argv, $namePath = "Common") {
	switch ($argv[1]) {
	case 'Model':
		Create("Application/Commons/Model/{$argv[2]}.php", $argv, $namePath);
		break;
	case 'Controller':
		Create("Application/Commons/Controller/{$argv[2]}.php", $argv, $namePath);
		break;
	case 'Project':
		CreateProject($argv[2]);
		break;
	default:
		exit("Type not is Model Controller Project\n");
		break;
	}
}

function CreatePathDefault($argv, $Path, $NamePath = "") {
	echo $Path . "\n";
	// exit();
	switch ($argv[1]) {
	case 'Model':
		CreateProject($argv[3]);
		Create("Application/{$Path}/Model/{$argv[2]}.php", $argv, $argv[3]);
		break;
	case 'Controller':
		Create("Application/{$Path}/Controller/{$argv[2]}.php", $argv, $argv[3]);
		break;
	case 'Project':
		CreateProject($argv[2]);
		break;
	default:
		exit("Type not is Model Controller Project\n");
		break;
	}
}

function CreateProject($ProjectName) {
	if (!file_exists("Application/{$ProjectName}")) {
		mkdir("Application/{$ProjectName}", 0777, true);
		mkdir("Application/{$ProjectName}/Controller", 0777, true);
		mkdir("Application/{$ProjectName}/Model", 0777, true);
		mkdir("Application/{$ProjectName}/View", 0777, true);
	} else {
		if (!file_exists("Application/{$ProjectName}/Controller")) {
			mkdir("Application/{$ProjectName}/Controller", 0777, true);
		}
		if (!file_exists("Application/{$ProjectName}/Model")) {
			mkdir("Application/{$ProjectName}/Model", 0777, true);
		}
		if (!file_exists("Application/{$ProjectName}/View")) {
			mkdir("Application/{$ProjectName}/View", 0777, true);
		}
	}
}

function Create($Path, $argv, $namePath) {
	$Files = fopen($Path, "w");
	$Text = $argv["1"]($namePath, $argv);
	fwrite($Files, $Text);
}

function Model($namePath, $argv) {
	$ModelText = "<?php\n";
	$ModelText .= "/**\n";
	$ModelText .= "*------Create thems Model------\n";
	$ModelText .= "*------SCWPHP  Version 1.0.0------\n";
	$ModelText .= "*------Dev Model Jions------\n";
	$t = date("Y-m-d H:i:s");
	$ModelText .= "*------Create Time {$t}------\n";
	$ModelText .= "*/\n";
	$ModelText .= "namespace App\\$namePath\\Model;\n";
	$ModelText .= "use Illuminate\Database\Eloquent\Model;\n";
	$ModelText .= "class " . $argv[2] . " extends Model {\n\n";
	// $ModelText .= "#protected $table = 'test';\n";
	$ModelText .= "}\n";
	return $ModelText;
}

function Controller($namePath, $argv) {
	$ModelText = "<?php\n";
	$ModelText .= "/**\n";
	$ModelText .= "*------Create thems Controller------\n";
	$ModelText .= "*------SCWPHP  Version 1.0.0------\n";
	$ModelText .= "*------Dev Model Jions------\n";
	$t = date("Y-m-d H:i:s");
	$ModelText .= "*------Create Time {$t}------\n";
	$ModelText .= "*/\n";
	$ModelText .= "namespace App\\$namePath\\Controller;\n";
	$ModelText .= "use etophp\\tool\Controller;\n\n";
	$ModelText .= "class " . $argv[2] . " extends Controller {\n\n";
	$ModelText .= "\tfunction __construct(){\n\n";
	$ModelText .= "\t}\n\n";
	$ModelText .= "\tPublic function Index(){\n\n";
	$ModelText .= "\t}\n";
	$ModelText .= "}\n";
	return $ModelText;

}