// Simulated globals (instead of DAT_1050_xxxx)
let globalState = {
  inCX: 0,
  ES: 0,
  SI: 0,
  DI: 0,
  BX: 0,
  taskInfoHigh: 0,
  versionInfo: 0,
  dosCallResult: 0,
  flagCF: 0,
};

function initTask(cs: number, param: number): number | null {
  // Simulate initializing a task; return some task info or null if fail
  console.log(`INITTASK called with CS=${cs}, param=${param}`);
  // For demo, just return a dummy 32-bit number (low/high parts)
  return 0x12340001; // low word non-zero, high word 0x1234
}

function getVersion(appSegment: number): number {
  console.log(`GETVERSION called with segment ${appSegment}`);
  return 0x101; // dummy version
}

function waitEvent(segment: number, param: number, val: number): void {
  console.log(`WAITEVENT with segment=${segment}, param=${param}, val=${val}`);
  // Simulate waiting for an event
}

function initApp(segment: number, di: number): boolean {
  console.log(`INITAPP with segment=${segment}, DI=${di}`);
  // Simulate app initialization success or failure
  return true; // let's say success for now
}

function fun_00e8() { console.log("FUN_00e8"); }
function fun_0332(seg: number) { console.log(`FUN_0332 with seg ${seg}`); }
function fun_04b4() { console.log("FUN_04b4"); }
function noop() { console.log("FUN_08fc"); }
function fun_00bc() { console.log("FUN_00bc"); }
function fun_01d9() { console.log("FUN_01d9"); }
function shutdown() { console.log("FUN_0549"); }
function fun_01e7() { console.log("FUN_01e7 called - retry or cleanup"); }

function entry() {
  // assume everything is set up
  fun_00e8();
  fun_0332(0x1048);
  fun_04b4();
  noop();
  fun_00bc();
  fun_01d9();
  shutdown();
}

// Run the entry simulation
entry();